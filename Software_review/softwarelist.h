#ifndef SOFTWARELIST_H
#define SOFTWARELIST_H
#include "softwarereview.h"

class SoftwareList
{
public:
    SoftwareList();
    void addReview(SoftwareReview s);
    QList<SoftwareReview> getSoftwareReview() const;

private:
    QList<SoftwareReview> reviewList;
};

#endif // SOFTWARELIST_H
