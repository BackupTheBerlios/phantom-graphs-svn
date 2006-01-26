//*******************************************************************************
/// @file	Grid.cpp
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		17.01.2006
/// @date	Letzte Änderung	26.01.2006
//*******************************************************************************

// Änderungen:
// 19.01.06		- Gitterpunkte auf dem Grid werden gerendert.
// 24.01.06		- Methoden isGridPoint() und nearestGridPoint() hinzugefügt und
//				  implementiert. 
// 26.01.06		- isGridPoint() und nearestGridPoint() beachten jetzt auch die 
//				  Ausgangsposition des Grid.

#include <math.h>

#include "Grid.h"
#include "GraphScene.h"

//*******************************************************************************
Grid::Grid( int cols, int rows )
{
	m_DisplayList = 0;
	m_Columns = cols;
	m_Rows = rows;
}
//*******************************************************************************

//*******************************************************************************
Grid::~Grid()
{
}
//*******************************************************************************

//*******************************************************************************
bool Grid::isGridPoint(Position pos)
{
	// linke untere Ecke des Grid ermitteln
	Position gridPos = getPosition();

	// Positionen relativ zum Grid betrachten (so tun, als wäre [0.0, 0.0] die 
	// Position des Grid).
	double x = pos.x - gridPos.x;
	double y = pos.y - gridPos.y;
	double z = pos.z - gridPos.z;

	double threshold = 0.01;

	// Prüfen, ob die x-Koordinate der Position nah genug an der x-Koordinate eines
	// gültigen Gitterpunktes ist
	// x-Koordinate nicht kleiner als linker Rand des Grid?
	bool xOk = x > -threshold;
	if (xOk)
	{
		double tmp = x / c_GridColumnWidth;
		// Abweichung von einer gültigen x-Koordinate klein genug?
		// rechts von gültiger Koordinate			links von gültiger Koordinate
		xOk = (fabs(tmp - (int)tmp) < threshold) || (fabs(tmp - (int)tmp) > (1.0 - threshold));
		// x-Koordinate nicht größer als rechter Rand des Grid?
		xOk = xOk && (x < ((m_Columns - 1) * c_GridColumnWidth + threshold));
	}

	// Prüfen, ob die y-Koordinate der Position nah genug an der y-Koordinate eines
	// gültigen Gitterpunktes ist
	bool yOk = y > -threshold;
	// Berechnung für y nur durchführen, wenn auch x Ok war.
	if (xOk && yOk)
	{
		double tmp = y / c_GridRowHeight;
		yOk = (fabs(tmp - (int)tmp) < threshold) || (fabs(tmp - (int)tmp) > (1.0 - threshold));
		yOk = yOk && (y < ((m_Rows - 1) * c_GridRowHeight + threshold));
	}

	// Prüfen, ob die z-Koordinate der Position nah genug an der z-Koordinate eines
	// gültigen Gitterpunktes ist
	bool zOk = fabs(z) < threshold;

	return (xOk && yOk && zOk);
}
//*******************************************************************************

//*******************************************************************************
Position Grid::nearestGridPoint(Position pos)
{
	// TODO muss Gridposition beachten

	// linke untere Ecke des Grid ermitteln
	Position gridPos = getPosition();

	// Positionen relativ zum Grid betrachten (so tun, als wäre [0.0, 0.0] die 
	// Position des Grid).
	double x = pos.x - gridPos.x;
	double y = pos.y - gridPos.y;

	// Ergebnisvariable
	Position gridPoint;

	double rightestX = gridPos.x + (m_Columns - 1) * c_GridColumnWidth;

	// nächstliegende x-Koordinate ermitteln:
	// alles, was links vom Grid liegt, wird auf x = gridPos.x gesetzt
	if (pos.x < gridPos.x)
	{
		gridPoint.x = gridPos.x;
	}
	// alles, was rechts vom Grid liegt, wird auf die letzte gültige x-Koordinate
	// des Grid gesetzt.
	else if (pos.x > rightestX)
	{
		gridPoint.x = rightestX;
	}
	// ansonsten auf den nächstgelegenen gültigen x-Wert runden
	else
	{
		int factor = (int)((x + (c_GridColumnWidth / 2)) / c_GridColumnWidth);
		gridPoint.x = gridPos.x + factor * c_GridColumnWidth;
	}

	double highestY = gridPos.y + (m_Rows - 1) * c_GridRowHeight;

	// nächstliegende y-Koordinate ermitteln:
	// alles, was unterhalb vom Grid liegt, wird auf y = gridPos.y gesetzt
	if (pos.y < gridPos.y)
	{
		gridPoint.y = gridPos.y;
	}
	// alles, was oberhalb vom Grid liegt, wird auf die letzte gültige y-Koordinate
	// des Grid gesetzt.
	else if (pos.y > highestY)
	{
		gridPoint.y = highestY;
	}
	// ansonsten auf den nächstgelegenen gültigen y-Wert runden
	else
	{
		int factor = (int)((y + (c_GridRowHeight / 2)) / c_GridRowHeight);
		gridPoint.y = gridPos.y + factor * c_GridRowHeight;
	}

	// z-Koordinate immer 0.0
	gridPoint.z = 0.0;

	return gridPoint;
}
//*******************************************************************************

//*******************************************************************************
void Grid::renderShape()
{
	if (m_DisplayList != 0)
    {
        glCallList(m_DisplayList);
    }
    else
    {
		float graphPlaneZ = GraphScene::getGraphPlaneZ();

        m_DisplayList = glGenLists(1);
        glNewList(m_DisplayList, GL_COMPILE_AND_EXECUTE);

		float x = 0.0f;
		float y = 0.0f;

		glBegin(GL_LINES);

		// Zeilen
		for (int i = 0; i < m_Rows; i++)
		{
			y = i * c_GridRowHeight;
			glVertex3f(0.0f,								y, graphPlaneZ);
			glVertex3f((m_Columns - 1) * c_GridColumnWidth,	y, graphPlaneZ);
		}

		// Spalten
		for (i = 0; i < m_Columns; i++)
		{
			x = i * c_GridColumnWidth;
			glVertex3f(x, 0.0f,								graphPlaneZ);
			glVertex3f(x, (m_Rows - 1) * c_GridRowHeight,	graphPlaneZ);
		}

		glEnd();

		// Gitterpunkte
		glColor3f(1.0f, 0.0f, 0.0f);
		glPointSize(2.5);
		glBegin(GL_POINTS);

		for (i = 0; i < m_Rows; i++)
		{
			y = i * c_GridRowHeight;
			for (int j = 0; j < m_Columns; j++)
			{
				x = j * c_GridColumnWidth;
				glVertex3f(x, y, graphPlaneZ);
				glVertex3f(x, y, graphPlaneZ);
			}
		}

		glEnd();

        glEndList();
    }
}
//*******************************************************************************

//*******************************************************************************
void Grid::renderDefaultGraphicProperties()
{
	glDisable(GL_LIGHTING);
	glColor3f(0.7f, 0.7f, 0.7f);
}
//*******************************************************************************