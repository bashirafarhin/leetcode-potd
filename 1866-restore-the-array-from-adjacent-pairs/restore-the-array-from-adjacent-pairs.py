class Solution:
    def restoreArray(self, adjacentPairs: List[List[int]]) -> List[int]:
        adjacency_map = {}
        for num in adjacentPairs:
            if num[0] not in adjacency_map:
                start = num[0]
                adjacency_map[num[0]] = [num[1]]
            else:
                adjacency_map[num[0]].append(num[1])
                
            if num[1] not in adjacency_map:
                end = num[1]
                adjacency_map[num[1]] = [num[0]]
            else:
                adjacency_map[num[1]].append(num[0])

        start, end = [k for k in adjacency_map.keys() if len(adjacency_map[k]) == 1 ]

        nums = [start]
        previous = None
        cur = start
        counter = 0
        while cur != end or cur == start:
            to_add = adjacency_map[cur][0] if adjacency_map[cur][0] != previous else adjacency_map[cur][1] 
            previous = cur

            nums.append(to_add)
            cur = to_add

        return nums 
        
        