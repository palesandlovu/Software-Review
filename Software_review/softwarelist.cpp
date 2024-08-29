#include "softwarelist.h"

SoftwareList::SoftwareList()
{
}
//append user input to list
void SoftwareList::addReview(SoftwareReview s)
{
    reviewList.append(s);
}
//get items in list
QList<SoftwareReview> SoftwareList::getSoftwareReview() const
{
    return reviewList;
}
