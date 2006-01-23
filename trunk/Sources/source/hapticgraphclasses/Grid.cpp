//*******************************************************************************
/// @file	Grid.cpp
/// @author	Katharina Greiner, Matr.-Nr. 943471
/// @date	Erstellt am		17.01.2006
/// @date	Letzte Änderung	19.01.2006
//*******************************************************************************

// Änderungen:
// 19.01.06		- Gitterpunkte auf dem Grid werden gerendert


#include "Grid.h"

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
void Grid::renderShape()
{
	if (m_DisplayList != 0)
    {
        glCallList(m_DisplayList);
    }
    else
    {
        m_DisplayList = glGenLists(1);
        glNewList(m_DisplayList, GL_COMPILE_AND_EXECUTE);

		float x = 0.0f;
		float y = 0.0f;

		glBegin(GL_LINES);

		// Zeilen
		for (int i = 0; i < m_Rows; i++)
		{
			y = i * c_GridRowHeight;
			glVertex3f(0.0f,								y, -0.1f);
			glVertex3f((m_Columns - 1) * c_GridColumnWidth,	y, -0.1f);
		}

		// Spalten
		for (i = 0; i < m_Columns; i++)
		{
			x = i * c_GridColumnWidth;
			glVertex3f(x, 0.0f,								-0.1f);
			glVertex3f(x, (m_Rows - 1) * c_GridRowHeight,	-0.1f);
		}

		glEnd();

		// Gitterpunkte
		glColor3f(1.0f, 0.0f, 0.0f);
		glPointSize(2.5);
		glBegin(GL_POINTS);

		for (i = 0; i < m_Rows; i++)
		{
			y = i * c_GridRowHeight;
//			glVertex3f(0.0f,								y, -0.1f);
//			glVertex3f((m_Columns - 1) * c_GridColumnWidth,	y, -0.1f);
			for (int j = 0; j < m_Columns; j++)
			{
				x = j * c_GridColumnWidth;
				glVertex3f(x, y, -0.1f);
				glVertex3f(x, y, -0.1f);
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