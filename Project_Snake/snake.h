#ifndef SNAKE_H
#define SNAKE_H

#include <QImage>
#include <QRect>
#include <stdio.h>
#include <stdlib.h>
#include <list>

class Snake
{
public:
  Snake(int,int,int);
  ~Snake(); /* 14 : destructors */
//Destructor is an instance member function which is invoked automatically whenever an object is going to be destroyed.
public:
  enum Direction { UP, DOWN, LEFT, RIGHT };
  struct Segment
  {
      Segment(QImage image, QRect rect, int x, int y)
                  : image(image)
                  , rect(rect)
                  , x(x)
                  , y(y)
                  { }

      QImage image;
      QRect rect;
      int x, y;
  };

  Direction dir;
  typedef std::list<Segment> SegmentList; /* 36 : Container Class */
//A container is a holder object that stores a collection of other objects (its elements).
  QImage image;
  SegmentList segments;

  void move();
  void putSegmentAt(QImage image, QRect rect, int x, int y);
  void growBy(unsigned int numSegments);



  const Segment & head() const /* 28 : Const references 4x */
  {
      return segments.front();
  }
  const Segment & tail() const
  {
      return segments.back();
  }

  typedef SegmentList::const_iterator SegmentIterator; /* 53 : Testing */
  SegmentIterator begin() const
  {
      return segments.begin();
  }

  SegmentIterator end() const
  {
      return segments.end();
  }

private:
  unsigned int numQueuedSegments;

};



#endif // SNAKE_H
