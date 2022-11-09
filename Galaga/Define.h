#pragma once

#define SAFE_DELETE(p) if(p) {delete p; p=NULL;}

const int STAGE_HEIGHT = 32;
const int STAGE_WIDTH  = 32;

const int ACTOR_SIZE = 2;

typedef struct tagPosition
{
	int x;
	int y;

	tagPosition() : x(0), y(0) {}

    tagPosition(const tagPosition& pos)
    {
        *this = pos;
    }

    tagPosition(int _x, int _y) : x(_x), y(_y) {}

    tagPosition operator +(const tagPosition& pos)
    {
        tagPosition p;
        p.x = x + pos.x, p.y = y + pos.y;
        return p;
    }

    tagPosition operator +(int a)
    {
        tagPosition p;
        p.x = x + a, p.y = y + a;
        return p;
    }

    void operator +=(const tagPosition& pos)
    {
        x += pos.x;
        y += pos.y;
    }

    void operator +=(int a)
    {
        x += a;
        y += a;
    }

    tagPosition operator -(int a)
    {
        tagPosition p;
        p.x = x - a, p.y = y - a;
        return p;
    }

    tagPosition operator -(const tagPosition& pos)
    {
        tagPosition p;
        p.x = x - pos.x, p.y = y - pos.y;
        return p;
    }

    void operator -=(int a)
    {
        x -= a, y -= a;
    }

    void operator -=(const tagPosition& pos)
    {
        x -= pos.x;
        y -= pos.y;
    }

    void operator =(const tagPosition& pos)
    {
        x = pos.x, y = pos.y;
    }

}POSITION, * PPOSITIOPN;


enum ACTOR_TYPE
{
    ACTOR_PLAYER = 100,
    ACTOR_PBULLET = 150,
    ACTOR_ENEMY1 = 200, 
    ACTOR_ENEMY2 = 201,
    ACTOR_ENEMY3 = 202,
    ACTOR_EBULLET = 250,
};