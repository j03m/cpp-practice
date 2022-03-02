#include <iostream>
#include <memory>

//v8
class  MeasureMemoryDelegate {
 public:
  virtual ~MeasureMemoryDelegate() = default;

  /**
   * Returns true if the size of the given context needs to be measured.
   */
  virtual bool ShouldMeasure() = 0;

  /**
   * This function is called when memory measurement finishes.
   *
   * \param context_sizes_in_bytes a vector of (context, size) pairs that
   *   includes each context for which ShouldMeasure returned true and that
   *   was not garbage collected while the memory measurement was in progress.
   *
   * \param unattributed_size_in_bytes total size of objects that were not
   *   attributed to any context (i.e. are likely shared objects).
   */
  virtual void MeasurementComplete(size_t unattributed_size_in_bytes) = 0;

};

//wtk2
struct SimpleMeasureMemoryDelegate {
    virtual bool ShouldMeasure() = 0;
    virtual void MeasurementComplete(size_t          *sizes,
                                     size_t          numItems,
                                     size_t          unattributed) = 0;
    virtual ~SimpleMeasureMemoryDelegate() {};
};

//wtk2
class MeasureMemoryAdapter : public MeasureMemoryDelegate {
    std::unique_ptr<SimpleMeasureMemoryDelegate, void(*)(SimpleMeasureMemoryDelegate*)> d_delegate_p;
  public:
    MeasureMemoryAdapter(SimpleMeasureMemoryDelegate *delegate, void(*deleter)(SimpleMeasureMemoryDelegate*))
    :d_delegate_p(std::move(delegate), deleter)
    {
        std::cout << "Adapter constructor!\n";
    }
    ~MeasureMemoryAdapter(){
        d_delegate_p.reset();
    }
    bool ShouldMeasure() { return true; }
    void MeasurementComplete(size_t unattributed_size_in_bytes) { return; };


    static void MeasureMemory(SimpleMeasureMemoryDelegate *delegate,
                              void(*deleter)(SimpleMeasureMemoryDelegate*));
};

//wtk2
void MeasureMemoryAdapter::MeasureMemory(SimpleMeasureMemoryDelegate *delegate,
                                         void(*deleter)(SimpleMeasureMemoryDelegate*)){
    MeasureMemoryAdapter adapter(delegate, deleter);
    std::cout << "measure memory with the adaptor!\n";
}


//rplus
struct RPMeasureMemoryDelegate : public SimpleMeasureMemoryDelegate {
        bool ShouldMeasure(){ return true; }
        void MeasurementComplete(size_t          *sizes,
                                 size_t          numItems,
                                 size_t          unattributed) {

        }
        ~RPMeasureMemoryDelegate(){
            std::cout << "RPMeasureMemoryDelegate destroyed\n";
        }

    };




int main () {
    RPMeasureMemoryDelegate *measureMemoryDelegate = new RPMeasureMemoryDelegate();
    MeasureMemoryAdapter::MeasureMemory(std::move(measureMemoryDelegate),
                                        [](SimpleMeasureMemoryDelegate *deleteMe){
                                            std::cout << "inside deleter\n";
                                            delete deleteMe;
                                        });
}