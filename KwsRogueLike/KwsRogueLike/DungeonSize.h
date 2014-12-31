#pragma once

class DungeonSize
{
public:

	DungeonSize(size_t sectionColumnNum, size_t sectionWidth, size_t sectionRowNum, size_t sectionHeight)
		: sectionColumnNum(sectionColumnNum),
		  sectionWidth(sectionWidth),
		  sectionRowNum(sectionRowNum),
		  sectionHeight(sectionHeight)
	{
	}

	size_t CalcTileRowNum()const
	{
		return sectionHeight*sectionRowNum;
	}

	size_t CalcTileColumnNum()const
	{
		return sectionWidth*sectionColumnNum;
	}

	size_t CalcSectionNum()const
	{
		return sectionRowNum*sectionColumnNum;
	}

	size_t GetSectionColumnNum() const
	{
		return sectionColumnNum;
	}

	size_t GetSectionWidth() const
	{
		return sectionWidth;
	}

	size_t GetSectionRowNum() const
	{
		return sectionRowNum;
	}

	size_t GetSectionHeight() const
	{
		return sectionHeight;
	}

private:
	size_t sectionColumnNum;
	size_t sectionWidth;

	size_t sectionRowNum;
	size_t sectionHeight;

};
