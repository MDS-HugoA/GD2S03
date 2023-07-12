#include <iostream>
#include <vector>

using namespace std;

enum CARD_SUIT
{
	CLUBS = 0,
	HEARTS,
	SPADES,
	DIAMONDS
};

struct Card
{
	CARD_SUIT m_suit;
	int m_rank;

	void Print()
	{
		switch (m_suit)
		{
		case CLUBS:
			printf("%c", 5);//♣
			break;
		case HEARTS:
			printf("%c", 3);//♥
			break;
		case SPADES:
			printf("%c", 6);//♠
			break;
		case DIAMONDS:
			printf("%c", 4);//♦
			break;
		}

		switch (m_rank)
		{
		case 1:
			printf("A");
			break;
		case 11:
			printf("J");
			break;
		case 12:
			printf("Q");
			break;
		case 13:
			printf("K");
			break;
		default:
			printf("%d", m_rank);
			break;
		}
	}
};

struct CardDeck
{
	Card m_deck[52];
	bool m_drawn[52];
	int m_totalDrawn = 0;
	
	void Generate()
	{
		for (int j = 0; j < 4; j++)//suit
		{
			for (int i = 0; i < 13; i++)//rank
			{
				m_deck[j * 13 + i].m_rank = i + 1;//cards start from 1
				m_deck[j * 13 + i].m_suit = CARD_SUIT(j);
				m_drawn[j * 13 + i] = false;
			}
		}
	}

	Card DrawCard()
	{
		if (m_totalDrawn == 52) 
		{
			//prevent infinite loop when drawing.
			m_totalDrawn = 0; 
			for (int i = 0; i < 52; i++)
			{
				m_drawn[i] = false;
			}
		}

		int index = -1;
		do
		{
			index = rand() % 52;

		} while (m_drawn[index] == true);

		m_drawn[index] = true;
		m_totalDrawn++;
		return m_deck[index];
	}
};

int HandValue(vector<Card> _hand)
{
	//to be implemented
	return 0;
}

void PrintHand(vector<Card> _hand)
{
	for (int i = 0; i < _hand.size(); i++)
	{
		_hand[i].Print();
		cout << ", ";
	}
}

int main()
{
	//Generate deck of cards
	CardDeck cardDeck;
	cardDeck.Generate();
	
	cout << "Welcome to Black Jack" << endl << endl;
	
	vector<Card> playerHand;
	vector<Card> dealerHand;

	playerHand.push_back(cardDeck.DrawCard());
	dealerHand.push_back(cardDeck.DrawCard());
	playerHand.push_back(cardDeck.DrawCard());
	dealerHand.push_back(cardDeck.DrawCard());

	cout << "Dealer has: ";
	PrintHand(dealerHand);
	cout << "value: " << HandValue(dealerHand) << endl << endl;

	cout << "You have: ";
	PrintHand(playerHand);
	cout << "value: " << HandValue(playerHand) << endl << endl;

	cout << "Draw Another?" << endl;
	//Tbc...

	return 0;
}
