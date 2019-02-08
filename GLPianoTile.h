#pragma once
#include "PlayScreenBase.h"
#include "Chart.h"
#include "GameInfo.h"
#include <random>
#include <string>

class GLPianoTile : public PlayScreenBase, public Chart, public GameInfo
{
public:
	GLPianoTile();
	~GLPianoTile();
};

