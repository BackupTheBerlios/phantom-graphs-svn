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

#include <windows.h>
#include <GL/glut.h>

#include <math.h>

#include "Grid.h"
#include "GraphScene.h"

//*******************************************************************************
Grid::Grid( UnitConversionInfo & unitInfo, int cols, int rows )
: m_rUnitInfo(unitInfo)
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

	float	gridColumnWidth	= m_rUnitInfo.getUnitWidth();
	float	gridRowHeight	= m_rUnitInfo.getUnitHeight();
	double	threshold = 0.1 * gridColumnWidth;

	// Prüfen, ob die x-Koordinate der Position nah genug an der x-Koordinate eines
	// gültigen Gitterpunktes ist
	// x-Koordinate nicht kleiner als linker Rand des Grid?
	bool xOk = x > -threshold;
	if (xOk)
	{
		double tmp = x / gridColumnWidth;
		// Abweichung von einer gültigen x-Koordinate klein genug?
		// rechts von gültiger Koordinate			links von gültiger Koordinate
		xOk = (fabs(tmp - (int)tmp) < threshold) || (fabs(tmp - (int)tmp) > (1.0 - threshold));
		// x-Koordinate nicht größer als rechter Rand des Grid?
		xOk = xOk && (x < ((m_Columns - 1) * gridColumnWidth + threshold));
	}

	// Prüfen, ob die y-Koordinate der Position nah genug an der y-Koordinate eines
	// gültigen Gitterpunktes ist
	bool yOk = y > -threshold;
	// Berechnung für y nur durchführen, wenn auch x Ok war.
	if (xOk && yOk)
	{
		double tmp = y / gridRowHeight;
		yOk = (fabs(tmp - (int)tmp) < threshold) || (fabs(tmp - (int)tmp) > (1.0 - threshold));
		yOk = yOk && (y < ((m_Rows - 1) * gridRowHeight + threshold));
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
	// linke untere Ecke des Grid ermitteln
	Position gridPos = getPosition();

	// Positionen relativ zum Grid betrachten (so tun, als wäre [0.0, 0.0] die 
	// Position des Grid).
	double x = pos.x - gridPos.x;
	double y = pos.y - gridPos.y;

	float	gridColumnWidth	= m_rUnitInfo.getUnitWidth();
	float	gridRowHeight	= m_rUnitInfo.getUnitHeight();

	// Ergebnisvariable
	Position gridPoint;

	double rightestX = gridPos.x + (m_Columns - 1) * gridColumnWidth;

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
		int factor = (int)((x + (gridColumnWidth / 2)) / gridColumnWidth);
		gridPoint.x = gridPos.x + factor * gridColumnWidth;
	}

	double highestY = gridPos.y + (m_Rows - 1) * gridRowHeight;

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
		int factor = (int)((y + (gridRowHeight / 2)) / gridRowHeight);
		gridPoint.y = gridPos.y + factor * gridRowHeight;
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
		float	graphPlaneZ = GraphScene::getGraphPlaneZ();
		float	gridColumnWidth	= m_rUnitInfo.getUnitWidth();
		float	gridRowHeight	= m_rUnitInfo.getUnitHeight();

        m_DisplayList = glGenLists(1);
        glNewList(m_DisplayList, GL_COMPILE_AND_EXECUTE);

		float x = 0.0f;
		float y = 0.0f;

		glLineWidth(1.0);
		glBegin(GL_LINES);

		// Zeilen
		for (int i = 0; i < m_Rows; i++)
		{
			y = i * gridRowHeight;
			glVertex3f(0.0f,								y, graphPlaneZ);
			glVertex3f((m_Columns - 1) * gridColumnWidth,	y, graphPlaneZ);
		}

		// Spalten
		for (i = 0; i < m_Columns; i++)
		{
			x = i * gridColumnWidth;
			glVertex3f(x, 0.0f,								graphPlaneZ);
			glVertex3f(x, (m_Rows - 1) * gridRowHeight,		graphPlaneZ);
		}

		glEnd();

		// Gitterpunkte
		glColor3f(1.0f, 0.0f, 0.0f);
		glPointSize(2.5);
		glBegin(GL_POINTS);

		for (i = 0; i < m_Rows; i++)
		{
			y = i * gridRowHeight;
			for (int j = 0; j < m_Columns; j++)
			{
				x = j * gridColumnWidth;
				glVertex3f(x, y, graphPlaneZ);
				glVertex3f(x, y, graphPlaneZ);
			}
		}

		glEnd();

		// Skala zeichnen
		GlutString::write("1", Position(0.0, -gridRowHeight, graphPlaneZ));

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