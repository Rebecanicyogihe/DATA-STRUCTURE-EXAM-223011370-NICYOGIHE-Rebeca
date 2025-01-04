def bucket_sort(data):
    if not data:
        print("No data to sort")
        return

    max_val = max(data)
    size = len(data)
    buckets = [[] for _ in range(size)]

    for num in data:
        index = min(num * size // (max_val + 1), size - 1)
        buckets[index].append(num)

    for bucket in buckets:
        bucket.sort()

    sorted_data = [num for bucket in buckets for num in bucket]
    print("Sorted Data:", sorted_data)

# Demo Bucket Sort
data = [45, 12, 78, 34, 23, 89, 67]
bucket_sort(data)