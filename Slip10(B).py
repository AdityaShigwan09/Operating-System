#Q.2 B) Write a python program to compute sum of Manhattan distance between all pairs of points.

def manhattan_distance(point1, point2):
    return abs(point1[0] - point2[0]) + abs(point1[1] - point2[1])

def sum_of_manhattan_distances(points):
    total_distance = 0
    n = len(points)
    
    for i in range(n):
        for j in range(i+1, n):
            distance = manhattan_distance(points[i], points[j])
            total_distance += distance
    
    return total_distance

# Example usage
points = [(1, 2), (3, 4), (5, 6), (7, 8)]
result = sum_of_manhattan_distances(points)
print(f"Sum of Manhattan distances between all pairs: {result}")