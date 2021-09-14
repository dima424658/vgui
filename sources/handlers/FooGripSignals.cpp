#include "FooGripSignals.hpp"

#include <VGUI_Frame.h>

FooTopGripSignal::FooTopGripSignal(vgui::Frame* frame)
    : FooDraggerSignal{ frame }
{}

FooBottomGripSignal::FooBottomGripSignal(vgui::Frame* frame)
    : FooDraggerSignal{ frame }
{}

FooLeftGripSignal::FooLeftGripSignal(vgui::Frame* frame)
    : FooDraggerSignal{ frame }
{}

FooRightGripSignal::FooRightGripSignal(vgui::Frame* frame)
    : FooDraggerSignal{ frame }
{}

FooTopLeftGripSignal::FooTopLeftGripSignal(vgui::Frame* frame)
    : FooDraggerSignal{ frame }
{}

FooTopRightGripSignal::FooTopRightGripSignal(vgui::Frame* frame)
    : FooDraggerSignal{ frame }
{}

FooBottomLeftGripSignal::FooBottomLeftGripSignal(vgui::Frame* frame)
    : FooDraggerSignal{ frame }
{}

FooBottomRightGripSignal::FooBottomRightGripSignal(vgui::Frame* frame)
    : FooDraggerSignal{ frame }
{}

FooCaptionGripSignal::FooCaptionGripSignal(vgui::Frame* frame)
    : FooDraggerSignal{ frame }
{}

void FooTopGripSignal::moved(int dx, int dy, bool internal, vgui::Panel* panel, vgui::Panel* parent)
{
    vgui::Panel* thisa;
    int dxa, dya;

    if (_frame->isSizeable())
    {
        if (internal)
        {
            panel->setPos(_dragOrgPos[0], dy + _dragOrgPos[1]);

            thisa = panel;
            dxa = _dragOrgSize[0];
            dya = _dragOrgSize[1] - dy;
        }
        else
        {
            parent->setPos(_dragOrgPos2[0], dy + _dragOrgPos2[1]);

            thisa = parent;
            dxa = _dragOrgSize2[0];
            dya = _dragOrgSize2[1] - dy;
        }

        thisa->setSize(dxa, dya);
    }
}

void FooBottomGripSignal::moved(int dx, int dy, bool internal, vgui::Panel* panel, vgui::Panel* parent)
{
    vgui::Panel* thisa;
    int dxa, dya;

    if (_frame->isSizeable())
    {
        if (internal)
        {
            thisa = panel;
            dxa = _dragOrgSize[0];
            dya = _dragOrgSize[1] + dy;
        }
        else
        {
            thisa = parent;
            dxa = _dragOrgSize2[0];
            dya = _dragOrgSize2[1] + dy;
        }
        thisa->setSize(dxa, dya);
    }
}

void FooLeftGripSignal::moved(int dx, int dy, bool internal, vgui::Panel* panel, vgui::Panel* parent)
{
    vgui::Panel* thisa;
    int dxa, dya;

    if (_frame->isSizeable())
    {
        if (internal)
        {
            panel->setPos(dx + _dragOrgPos[0], _dragOrgPos[1]);

            thisa = panel;
            dxa = _dragOrgSize[0] - dx;
            dya = _dragOrgSize[1];
        }
        else
        {
            parent->setPos(dx + _dragOrgPos2[0], _dragOrgPos2[1]);

            thisa = parent;
            dxa = _dragOrgSize2[0] - dx;
            dya = _dragOrgSize2[1];
        }

        thisa->setSize(dxa, dya);
    }
}

void FooRightGripSignal::moved(int dx, int dy, bool internal, vgui::Panel* panel, vgui::Panel* parent)
{
    vgui::Panel* thisa;
    int dxa, dya;

    if (_frame->isSizeable())
    {
        if (internal)
        {
            thisa = panel;
            dxa = _dragOrgSize[0] + dx;
            dya = _dragOrgSize[1];
        }
        else
        {
            thisa = parent;
            dxa = _dragOrgSize2[0] + dx;
            dya = _dragOrgSize2[1];
        }

        thisa->setSize(dxa, dya);
    }
}

void FooTopLeftGripSignal::moved(int dx, int dy, bool internal, vgui::Panel* panel, vgui::Panel* parent)
{
    vgui::Panel* thisa;
    int dxa, dya;

    if (_frame->isSizeable())
    {
        if (internal)
        {
            panel->setPos(dx + _dragOrgPos[0], _dragOrgPos[1] + dy);

            thisa = panel;
            dya = _dragOrgSize[1] - dy;
            dxa = _dragOrgSize[0] - dx;
        }
        else
        {
            parent->setPos(dx + _dragOrgPos2[0], _dragOrgPos2[1]);

            thisa = parent;
            dya = _dragOrgSize2[1] + dy;
            dxa = _dragOrgSize2[0] - dx;
        }
        thisa->setSize(dxa, dya);
    }
}

void FooTopRightGripSignal::moved(int dx, int dy, bool internal, vgui::Panel* panel, vgui::Panel* parent)
{
    vgui::Panel* thisa;
    int dxa, dya;

    if (_frame->isSizeable())
    {
        if (internal)
        {
            panel->setPos(_dragOrgPos[0], dy + _dragOrgPos[1]);

            thisa = panel;
            dya = _dragOrgSize[1] - dy;
            dxa = _dragOrgSize[0] + dx;
        }
        else
        {
            parent->setPos(_dragOrgPos2[0], dy + _dragOrgPos2[1]);

            thisa = parent;
            dya = _dragOrgSize2[1] - dy;
            dxa = _dragOrgSize2[0] + dx;
        }
        thisa->setSize(dxa, dya);
    }
}

void FooBottomLeftGripSignal::moved(int dx, int dy, bool internal, vgui::Panel* panel, vgui::Panel* parent)
{
    vgui::Panel* thisa;
    int dxa, dya;

    if (_frame->isSizeable())
    {
        if (internal)
        {
            panel->setPos(dx + _dragOrgPos[0], _dragOrgPos[1]);

            thisa = panel;
            dya = _dragOrgSize[1] + dy;
            dxa = _dragOrgSize[0] - dx;
        }
        else
        {
            parent->setPos(dx + _dragOrgPos2[0], _dragOrgPos2[1]);

            thisa = parent;
            dya = _dragOrgSize2[1] + dy;
            dxa = _dragOrgSize2[0] - dx;
        };

        thisa->setSize(dxa, dya);
    }
}

void FooBottomRightGripSignal::moved(int dx, int dy, bool internal, vgui::Panel* panel, vgui::Panel* parent)
{
    vgui::Panel* thisa;
    int dxa, dya;

    if (_frame->isSizeable())
    {
        if (internal)
        {
            thisa = panel;
            dya = _dragOrgSize[1] + dy;
            dxa = _dragOrgSize[0] + dx;
        }
        else
        {
            thisa = parent;
            dya = _dragOrgSize2[1] + dy;
            dxa = _dragOrgSize2[0] + dx;
        }
        thisa->setSize(dxa, dya);
    }
}

void FooCaptionGripSignal::moved(int dx, int dy, bool internal, vgui::Panel* panel, vgui::Panel* parent)
{
    vgui::Panel* thisa;
    int dxa, dya;

    if (_frame->isMoveable())
    {
        if (internal)
        {
            thisa = panel;
            dya = _dragOrgPos[1] + dy;
            dxa = _dragOrgPos[0] + dx;
        }
        else
        {
            thisa = parent;
            dya = _dragOrgPos2[1] + dy;
            dxa = _dragOrgPos2[0] + dx;
        }
        thisa->setPos(dxa, dya);
    }
}