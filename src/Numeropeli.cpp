#include "Numeropeli.h"
#include <stdlib.h>
#include <iomanip>
#include <iostream>

using namespace std;

Numeropeli::Numeropeli(void)
{
	m_arvo = (int*)malloc(16*sizeof(int));
	for( int i=0; i<15 ; ++i )
	{
		m_arvo[i] = i + 1;
	}
	m_arvo[15] = 0;
}

Numeropeli::~Numeropeli(void)
{
	free(m_arvo);
}

void Numeropeli::sekoita(void)
{
	for(int i=0;i<16;++i)
		*(m_arvo + i) = i;
	srand(time(0));
	int mista,mihin,temp;
	for(int i=0;i<500;++i)
	{
		mista = rand() % 16;
		mihin = rand() % 16;
		if(mista == mihin)
			continue;
		temp = *(m_arvo + mihin);
		*(m_arvo + mihin) = *(m_arvo + mista);
		*(m_arvo + mista) = temp;
	}
	/*
	for(int i=0;i<16;++i)
	{
		cout << setw(3) << *(m_arvo + i);
		if(i%4 == 3)
			cout << endl;
	}
	cout << endl;
	*/
}

bool Numeropeli::siirto(int numero)
{
	if(numero < 1 || numero > 15)
		return false;
	int num_loc, zero_loc;
	for(int i=0;i<16;++i)
	{
		if( *(m_arvo + i) == numero )
			num_loc = i;
		if( *(m_arvo + i) == 0 )
			zero_loc = i;
	}
	/*
	cout << num_loc << endl;
	cout << zero_loc << endl;
	*/
	bool top,bottom,right,left;
	top = bottom = right = left = true;
	if(zero_loc < 4)
		top = false;
	if(zero_loc > (15-4))
		bottom = false;
	if(zero_loc%4 == 0)
		left = false;
	if(zero_loc%4 == 3)
		right = false;
	bool numIsAcceptable = false;
	if(top) {
		if(zero_loc - 4 == num_loc)
			numIsAcceptable = true;
    }
	else if( right ) {
		if(zero_loc + 1 == num_loc)
			numIsAcceptable = true;
    }
	else if( bottom ) {
		if(zero_loc + 4 == num_loc )
			numIsAcceptable = true;
    }
	else if( left )
		if(zero_loc - 1 == num_loc )
			numIsAcceptable = true;
	if(!numIsAcceptable)
		return false;
	*(m_arvo + zero_loc) = numero;
	*(m_arvo + num_loc) = 0;
	/*
	for(int i=0;i<16;++i)
	{
		cout << setw(3) << *(m_arvo + i);
		if(i%4 == 3)
			cout << endl;
	}
	cout << endl;
	*/
	return false;
}

bool Numeropeli::isFinished(void) const
{
	for ( int i = 0; i<15;++i)
		if(m_arvo[i] != (i+1)) return false;
	return true;
}

int* Numeropeli::getVals(void) const
{
	return this->m_arvo;
}

Numeropeli::Numeropeli(Numeropeli& alkuperainen)
{
	// sis��nrakennettu tekisi n�in : 
	// m_arvo = alkuper�inen.m_arvo;
	m_arvo = (int*)malloc(16*sizeof(int));
	for( int i=0; i<15 ; ++i )
	{
		m_arvo[i] = i + 1;
	}
	m_arvo[15] = 0;
}
