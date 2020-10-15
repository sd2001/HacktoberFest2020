# euclidean

def euclidean_distance(pt1, pt2):
    distance = 0
    for i in range(len(pt1)):
        distance = distance + (pt1[i] - pt2[i]) ** 2

    distance = distance ** 0.5
    return distance