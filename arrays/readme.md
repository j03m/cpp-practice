# Merging Ranges

Key to avoiding n^2 is that the times must be sorted by start time which is n log n

Then we can iterate over them and merge them intelligently. 

Logic:

1) init our vector with meeting 1 (sorted) - this is the earliest possible start time
2) Check if a new meeting's start < our current merge meetings end
3) If so, update the current merged meeting with the MAX end time
4) If not, add the new meeting to the merged meeting list
5) repeat


so given:

```c++
meetings.push_back(Meeting(9,10));
meetings.push_back(Meeting(10,12));
meetings.push_back(Meeting(4,8));
meetings.push_back(Meeting(3,5));
meetings.push_back(Meeting(0,1));
```

sort to:

```c++
0,1
3,5
4,8
9,10
10,12
```

Then: 

```
merged = [{0,1}] | current = {0,1} 
// basically a noop iteration

merged = [{0,1}] | current = {3,5} 
// no overlap so push

merged = [{0, 1}, {3,5}] | current = {4, 8} 
// 4 <= 5 update

merged = [{0, 1}, {3,8}] | current = {9, 10} 
// no overlap so push 

merged = [{0, 1}, {3,8}, {9,10}] | current = {10, 12} 
// 10 < 12 update

merged = [{0, 1}, {3,8}, {9, 11}] 
``` 




