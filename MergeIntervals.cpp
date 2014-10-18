bool cmp(const Interval & T1, const Interval & T2)
{
	if (T1.start < T2.start)
		return true;
	else if (T1.start > T2.start)
		return false;
	else
		return T1.end < T2.end;
}
class Solution
{
	public:

	vector<Interval> merge(vector<Interval> &intervals)
	{
		sort(intervals.begin(), intervals.end(), cmp);
		vector<Interval> returnVec;
		int size = intervals.size();
		if (size == 0)
			return returnVec;
		int left = intervals[0].start;
		int right = intervals[0].end;
		for (int  i = 1; i < size; i++)
		{
			if (intervals[i].start > right)
			{
				returnVec.push_back(Interval(left, right));
				left = intervals[i].start;
				right = intervals[i].end;
			}
			else
				right = max(right, intervals[i].end);
		}
		returnVec.push_back(Interval(left, right));
		return returnVec;
	}

};
