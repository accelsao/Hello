from collections import defaultdict
class Graph:
    def init(self,vertices):
        self.V=vertices
        self.graph=[]
    def addEdge(self, u, v, w):
            self.graph.append([u, v, w])
    def find(self, parent, i):
        if parent[i] == i:
            return i
        parent[i]=self.find(parent, parent[i])
        return parent[i]
    def mst(self):
        ans=i=e=0
        self.graph=sorted(self.graph,key=lambda item:item[2])
        parent=[]
        for node in range(self.V):
            parent.append(node)
        while e<self.V-1:
            u,v,w=self.graph[i]
            i+=1
            x = self.find(parent, u)
            y = self.find(parent, v)
            if x==y:continue
            e+=1
            ans+=w
            parent[x]=y
        return ans
n=int(input())
p=list(map(int,input().split()))
g=Graph()
g.init(n)
for i in range(0,n):
    for j in range(i+1,n):
        g.addEdge(i,j,p[i]^p[j])
print(g.graph)
print(g.mst())
