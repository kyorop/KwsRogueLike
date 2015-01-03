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

	size_t DungeonHeight() const
	{
		return sectionHeight*sectionRowNum;
	}

	size_t DungeonWidth() const
	{
		return sectionWidth*sectionColumnNum;
	}

	size_t AllSectionNum() const
	{
		return sectionRowNum*sectionColumnNum;
	}

	size_t DungeonColumnNum() const
	{
		return sectionColumnNum;
	}

	size_t SectionWidth() const
	{
		return sectionWidth;
	}

	size_t DungeonRowNum() const
	{
		return sectionRowNum;
	}

	size_t SectionHeight() const
	{
		return sectionHeight;
	}

private:
	size_t sectionColumnNum;
	size_t sectionWidth;

	size_t sectionRowNum;
	size_t sectionHeight;

};
