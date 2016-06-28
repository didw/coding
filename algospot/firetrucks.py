import sys
import gc
from Queue import Queue

inp = lambda: sys.stdin.readline()

for _ in range(int(inp())):
    gc.collect()
    ins = inp().split()
    V = int(ins[0])
    E = int(ins[1])
    n = int(ins[2])
    m = int(ins[3])
    edges = [[] for _ in xrange(V)]
    for _ in xrange(E):
        ins = inp().split()
        a = int(ins[0])-1
        b = int(ins[1])-1
        t = int(ins[2])
        edges[a].append([b,t])
        edges[b].append([a,t])
    q = Queue()
    fire_places = map(lambda x:int(x)-1, inp().split())
    fire_station = map(lambda x:int(x)-1, inp().split())
    dist = [987654321 for _ in xrange(V)]
    for fs in fire_station:
        dist[fs] = 0
        q.put(fs)
    while not q.empty():
        here = q.get()
        for there, w in edges[here]:
            if dist[there] > dist[here] + w:
                dist[there] = dist[here] + w
                q.put(there)
    res = 0
    for fp in fire_places:
        res += dist[fp]
    print(res)

    

    

