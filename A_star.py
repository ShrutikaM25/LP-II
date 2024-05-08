class box:

    def __init__(self, par = None, pos = None):
        self.g = 0
        self.h = 0
        self.f = 0
        self.par = par
        self.pos = pos

    def __eq__(self, x):
        return self.pos == x.pos

class A_Star:

    def __init__(self):
        self.open = []
        self.close = []
        self.start = None
        self.end = None
        self.maze = None

    def findPath(self, start, end, maze):

        self.start = box(None, start)
        self.end = box(None, end)
        self.maze = maze
        self.open.append(self.start)

        while len(self.open)>0:

            curNode = self.open[0]
            curPos = 0

            # I] Finding the least f item and pop it from the open list
            for ind,item in enumerate(self.open):

                if curNode.f > item.f:
                    curNode = item
                    curPos = ind

            self.open.pop(curPos)
            self.close.append(curNode)

            # II] If current node is the destination node, rer
            if curNode == self.end:

                retList = []
                curr = curNode

                while curr is not None:
                    retList.append(curr.pos)
                    curr = curr.par

                return retList[::-1]

            #III] Finding successors

            successors = []
            for new_pos in [(1,0),(-1,0),(0,1),(0,-1),(1,-1),(1,1),(-1,1),(-1,-1)]:

                succ_pos = ((curNode.pos[0] + new_pos[0]), (curNode.pos[1] + new_pos[1]))
                if succ_pos[0] < 0 or succ_pos[1] < 0 or succ_pos[0] > (len(maze) - 1) or succ_pos[1] > (len(maze[len(maze)-1])-1):
                    continue
                if maze[succ_pos[0]][succ_pos[1]] == 1:
                    continue
                succ = box(curNode, succ_pos)
                successors.append(succ)

            #IV] Calculate successors' f value and add it to the open list

            for succ in successors:

                label = 0
                if succ in self.close:
                    continue

                succ.g = succ.g + 1
                succ.h = ((succ.pos[0] - self.end.pos[0])**2 + (succ.pos[1] - self.end.pos[1])**2)
                succ.f = succ.g + succ.h

                for item in self.open:
                    if succ == item and succ.g > item.g:
                        label = 1

                if(label == 1):
                    continue

                self.open.append(succ)

A1 = A_Star()
path = A1.findPath((0,0),(0,9),
     [[0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 1, 0, 0, 0, 0, 0],     
            [0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 1, 0, 0, 0, 0, 0]])
print("The valid path is:",path)