#pragma once

#include "FooDraggerSignal.hpp"

class FooTopGripSignal : public FooDraggerSignal
{
public:
    FooTopGripSignal(vgui::Frame* frame);
    virtual void moved(int dx, int dy, bool internal, vgui::Panel* panel, vgui::Panel* parent);
};

class FooBottomGripSignal : public FooDraggerSignal
{
public:
    FooBottomGripSignal(vgui::Frame* frame);
    virtual void moved(int dx, int dy, bool internal, vgui::Panel* panel, vgui::Panel* parent);
};

class FooLeftGripSignal : public FooDraggerSignal
{
public:
    FooLeftGripSignal(vgui::Frame* frame);
    virtual void moved(int dx, int dy, bool internal, vgui::Panel* panel, vgui::Panel* parent);
};

class FooRightGripSignal : public FooDraggerSignal
{
public:
    FooRightGripSignal(vgui::Frame* frame);
    virtual void moved(int dx, int dy, bool internal, vgui::Panel* panel, vgui::Panel* parent);
};

class FooTopLeftGripSignal : public FooDraggerSignal
{
public:
    FooTopLeftGripSignal(vgui::Frame* frame);
    virtual void moved(int dx, int dy, bool internal, vgui::Panel* panel, vgui::Panel* parent);
};

class FooTopRightGripSignal : public FooDraggerSignal
{
public:
    FooTopRightGripSignal(vgui::Frame* frame);
    virtual void moved(int dx, int dy, bool internal, vgui::Panel* panel, vgui::Panel* parent);
};

class FooBottomLeftGripSignal : public FooDraggerSignal
{
public:
    FooBottomLeftGripSignal(vgui::Frame* frame);
    virtual void moved(int dx, int dy, bool internal, vgui::Panel* panel, vgui::Panel* parent);
};

class FooBottomRightGripSignal : public FooDraggerSignal
{
public:
    FooBottomRightGripSignal(vgui::Frame* frame);
    virtual void moved(int dx, int dy, bool internal, vgui::Panel* panel, vgui::Panel* parent);
};


class FooCaptionGripSignal : public FooDraggerSignal
{
public:
    FooCaptionGripSignal(vgui::Frame* frame);
    virtual void moved(int dx, int dy, bool internal, vgui::Panel* panel, vgui::Panel* parent);
};