class Solution
{
	public:
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
	{
		int start = newInterval.start;
		int end = newInterval.end;
		int startIndex = search(intervals, start);
		int endIndex = search(intervals, end);
		int size = intervals.size();
		vector<Interval> returnVec;
		if (size == 0)
		{
			returnVec.push_back(newInterval);
			return returnVec;
		}
		for (int i = 0; i < startIndex; i++)
			returnVec.push_back(intervals[i]);
		int leftBound, rightBound;
		if (startIndex == size)
			leftBound = start;
		else
		{
			if (start >= intervals[startIndex].start)
				leftBound = intervals[startIndex].start;
			else
				leftBound = start;
		}
		if (endIndex == size)
			rightBound = end;
		else
		{
			if (end >= intervals[endIndex].start)
				rightBound = intervals[endIndex].end;
			else
				rightBound = end;
		}
		returnVec.push_back(Interval(leftBound, rightBound));
		if (endIndex != size && end >= intervals[endIndex].start)
		{
			for (int i = endIndex + 1; i < size; i++)
				returnVec.push_back(intervals[i]);
		}
		else
			for (int i = endIndex; i < size; i++)
				returnVec.push_back(intervals[i]);
		return returnVec;
	}
	int search(vector<Interval> & intervals, int num)
	{
		int size = intervals.size();
		int left = 0, right = size, mid;
		while (left < right)
		{
			mid = (left + right) / 2;
			if (num >= intervals[mid].start && num <= intervals[mid].end)
				return mid;
			else if (num > intervals[mid].end)
				left = mid + 1;
			else
				right = mid;
		}
		return right;
	}
};
