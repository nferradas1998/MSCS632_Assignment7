class StatisticsCalculator:
    def __init__(self, data):
        self.data = data

    def mean(self):
        return sum(self.data) / len(self.data)

    def median(self):
        sorted_data = sorted(self.data)
        n = len(sorted_data)
        mid = n // 2
        if n % 2:
            return sorted_data[mid]
        return (sorted_data[mid-1] + sorted_data[mid]) / 2

    def mode(self):
        freq = {}
        for x in self.data:
            freq[x] = freq.get(x, 0) + 1
        max_count = max(freq.values())
        return [x for x, count in freq.items() if count == max_count]

if __name__ == "__main__":
    data = [1, 2, 2, 3, 4, 4, 4, 5]
    stats = StatisticsCalculator(data)
    print(f"Mean:   {stats.mean():.2f}")
    print(f"Median: {stats.median():.2f}")
    print(f"Mode:   {', '.join(map(str, stats.mode()))}")
