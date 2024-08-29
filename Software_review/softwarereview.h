#ifndef SOFTWAREREVIEW_H
#define SOFTWAREREVIEW_H
#include <QString>
#include <QDate>

class SoftwareReview
{
public:
    SoftwareReview();
    SoftwareReview(QString n, QDate d, bool r);
    virtual QString toString();
    void setName(QString n);
    QString getName() const;
    void setDate(QDate d);
    QDate getDate() const;
    void setRecommendation(bool r);
    QString getRecommendation() const;

private:
    QString softwareName;
    QDate reviewDate;
    bool softwareRecommendation;
};

#endif // SOFTWAREREVIEW_H
