#include "SectionUtil.h"
#include "Section.h"

void SectionUtil::ConnectToEachOther(Section* sec1, Section* sec2)
{
	sec1->SetRoomConnected(sec2);
	sec2->SetRoomConnected(sec1);
}