import sys
from Queue import Queue
import math
import gc

rl = lambda: sys.stdin.readline()
C = int(rl())
while(C):
    gc.collect()
    C -= 1
    elems = rl().split()
    N = int(elems[0])
    M = int(elems[1])
    edges = [[] for _ in xrange(N)]
    for i in range(M):
        elems = rl().split()
        a = int(elems[0])
        b = int(elems[1])
        c = math.log(float(elems[2]))
        edges[a].append([b, c])
        edges[b].append([a, c])
    q = Queue()
    q.put(0)
    dist = [987654321.0 for _ in xrange(N)]
    dist[0] = 0
    while(not q.empty()):
        here = q.get()
        for there, w in edges[here]:
            if dist[there] > dist[here] + w:
                dist[there] = dist[here] + w
                q.put(there)
    print("{:.10f}".format(math.exp(dist[N-1])))



