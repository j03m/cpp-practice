#include <iostream>
#include <unordered_set>
#include <vector>
#include <sstream>
#include <stdexcept>
using namespace std;

class GraphNode
{
private:
    string label_;
    unordered_set<GraphNode*> neighbors_;
    string color_;

public:
    GraphNode(const string& label) :
        label_(label),
        neighbors_(),
        color_()
    {
    }

    const string& getLabel() const
    {
        return label_;
    }

    const unordered_set<GraphNode*> getNeighbors() const
    {
        return neighbors_;
    }

    void addNeighbor(GraphNode& neighbor)
    {
        neighbors_.insert(&neighbor);
    }

    bool hasColor() const
    {
        return !color_.empty();
    }

    const string& getColor() const
    {
        if (hasColor()) {
            return color_;
        }
        else {
            throw logic_error("GraphNode is not marked with color");
        }
    }

    void setColor(const string& color)
    {
        color_ = color;
    }
};


void colorGraph(const vector<GraphNode*>& graph, const vector<string>& colors){
    for (auto node : graph){
        const auto& neighbors = node->getNeighbors();
        unordered_set<string> illegalColors;
        for(const auto neighbor : neighbors){
            if (neighbor == node) {
                ostringstream errorMessage;
                errorMessage << "Legal coloring impossible for node with loop: "
                        << node->getLabel();
                throw invalid_argument(errorMessage.str());
            }
            if (neighbor->hasColor()){
                illegalColors.insert(neighbor->getColor());
            }
        }

        bool wasSet = false;
        for (const auto color : colors){
            if (illegalColors.find(color) == illegalColors.cend()){
                node->setColor(color);
                wasSet = true;
                break;
            }
        }

        //verify set or throw...
        if (!wasSet){
            throw logic_error("we didn't set a color...?");
        }
    }
}

int main(){
    GraphNode a("a");
    GraphNode b("b");
    GraphNode c("c");

    a.addNeighbor(b);
    b.addNeighbor(a);
    b.addNeighbor(c);
    c.addNeighbor(b);
    //a.addNeighbor(a);

    vector<GraphNode*> graph { &a, &b, &c };
    vector<string> colors = { "r", "g", "b", "y"};
    colorGraph(graph, colors);

    for (auto node : graph){
        cout << node->getLabel() << " " << node->getColor() << "\n";
        for (auto neighbor : node->getNeighbors()){
            cout << "\t" << neighbor->getLabel() << " " << neighbor->getColor() << "\n";
        }
    }

}
