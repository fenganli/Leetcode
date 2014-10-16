class Solution
{
	public:
	string intToRoman(int num)
	{
		string returnStr = "";
		while (num >= 1000)
		{
			returnStr += 'M';
			num -= 1000;
		}
		if (num >= 900)
		{
			returnStr += "CM";
			num -= 900;
		}
		if (num >= 500)
		{
			returnStr += 'D';
			num -= 500;
		}
		if (num >= 400)
		{
			returnStr += "CD";
			num -= 400;
		}
		while (num >= 100)
		{
			returnStr += 'C';
			num -= 100;
		}
		if (num >= 90)
		{
			returnStr += "XC";
			num -= 90;
		}
		if (num >= 50)
		{
			returnStr += 'L';
			num -= 50;
		}
		if (num >= 40)
		{
			returnStr += "XL";
			num -= 40;
		}
		while (num >= 10)
		{
			returnStr += 'X';
			num -= 10;
		}
		if (num >= 9)
		{
			returnStr += "IX";
			num -= 9;
		}
		if (num >= 5)
		{
			returnStr += 'V';
			num -= 5;
		}
		if (num >= 4)
		{
			returnStr += "IV";
			num -= 4;
		}
		while (num >= 1)
		{
			returnStr += 'I';
			num --;
		}
		return returnStr;
	}
};
