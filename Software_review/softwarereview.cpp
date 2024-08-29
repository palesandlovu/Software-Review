#include "softwarereview.h"
#include <QList>
#include <QDate>

SoftwareReview::SoftwareReview()
{
}

SoftwareReview::SoftwareReview(QString n, QDate d, bool r)
    :softwareName(n), reviewDate(d), softwareRecommendation(r)
{

}
//format to use when displaying list
QString SoftwareReview::toString()
{

    QString review = "Software Name: " + softwareName +
                     "\tDate: " + reviewDate.toString("yyyy/MM/dd") +
                     "\tRecommend? " + getRecommendation();
    return review;
}

void SoftwareReview::setName(QString name)
{
    softwareName = name;
}


QString SoftwareReview::getName() const
{
    return softwareName;
}

void SoftwareReview::setDate(QDate date)
{
    reviewDate = date;
}

QDate SoftwareReview::getDate() const
{
    return reviewDate;
}


void SoftwareReview::setRecommendation(bool recommend)
{
    softwareRecommendation = recommend;
}

//true/false  to yes/no
QString SoftwareReview::getRecommendation() const
{
    if (softwareRecommendation == true)
        return "Yes";

    return "No";
}
