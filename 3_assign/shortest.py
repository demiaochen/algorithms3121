# Python3 implementation of the above approach
inf = 100000000
 
# Function to find the smallest path
# with exactly K edges
def smPath(s, d, ed, n, k):
     
    # Array to store dp
    dis = [inf] * (n + 1)
    dis[s] = 0
 
    # Loop to solve DP
    for i in range(k):
 
        # Initialising next state
        dis1 = [inf] * (n + 1)
 
        # Recurrence relation
        for it in ed:
            dis1[it[1]] = min(dis1[it[1]],
                            dis[it[0]]+ it[2])
        for i in range(n + 1):
            dis[i] = dis1[i]
 
    # Returning final answer
    if (dis[d] == inf):
        return -1
    else:
        return dis[d]
 
# Driver code
if __name__ == '__main__':
 
    n = 4
 
    # Input edges
    ed = [ [0, 1 ,10],
           [ 0, 2 ,3],
           [ 0, 3 ,2],
           [ 1, 3 ,7],
           [ 2, 3 ,7] ]
 
    # Source and Destination
    s = 0
    d = 3
 
    # Number of edges in path
    k = 2
 
    # Calling the function
    print(smPath(s, d, ed, n, k))
 
# This code is contributed by mohit kumar 29