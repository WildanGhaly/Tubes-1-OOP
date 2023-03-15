#include "SwapCard.hpp"

using namespace std;

SwapCard::SwapCard() : Ability::Ability(6){
    
}

bool SwapCard::useAbility(Game<Card>& game, int playerAbility, int playerNumber){


    if (playerAbility == 5){
        if (SwapCard::isUsingAbility() == false){
            cout<<game.getPlayer(playerNumber).getName()<<" Melakukan SWAPCARD"<<endl;
            cout << "Silahkan pilih pemain yang kartunya ingin anda tukar:" << endl;
            int player1,player2,player1CardIdx,player2CardIdx;
            for(int i=0;i<game.getPlayers().size();i++){
                if(i != playerNumber){
                    cout<< i+1 <<"." << game.getPlayer(i).getName()<<endl;
                }
            }
            cin>>player1;
            player1--;
            cout << "Silahkan pilih pemain lain yang kartunya ingin anda tukar:" << endl;
            for(int i=0;i<game.getPlayers().size();i++){
                if(i != playerNumber){
                    cout<< i+1 <<"." << game.getPlayer(i).getName()<<endl;
                }
            }
            cin>>player2;
            player2--;

            cout<< "Silahkan pilih kartu kanan/kiri "<< game.getPlayer(player1).getName() << endl;
            cout<<"1. Kiri\n2.Kanan"<<endl;
            cin>>player1CardIdx;
            player1CardIdx--;
            cout<< "Silahkan pilih kartu kanan/kiri "<< game.getPlayer(player2).getName() << endl;
            cout<<"1. Kiri\n2.Kanan"<<endl;
            cin>>player2CardIdx;
            player2CardIdx--;

            Card player1Card = game.getPlayer(player1).getHand(player1CardIdx);
            Card player2Card = game.getPlayer(player2).getHand(player2CardIdx);
            CardList<Card> temp1, temp2;

            if(player2CardIdx == 0){
                temp1.addCard(player1Card);
                temp1.addCard(game.getPlayer(player2).getHand(1));
            }else if(player2CardIdx == 1){
                temp1.addCard(game.getPlayer(player2).getHand(0));
                temp1.addCard(player1Card);
            }
            if(player1CardIdx == 0){
                temp2.addCard(player2Card);
                temp2.addCard(game.getPlayer(player1).getHand(1));
            }else if(player1CardIdx == 1){
                temp2.addCard(game.getPlayer(player1).getHand(0));
                temp2.addCard(player2Card);
            }

            Player playerr1,playerr2,playerr3;
            playerr1 = game.getPlayer(player1);
            playerr2 = game.getPlayer(player2);
            playerr3 = game.getPlayer(playerNumber);
            playerr2.setHand(temp1);
            playerr1.setHand(temp2);
            playerr3.setAbility(-1);
            game.setPlayer(player1,playerr1);
            game.setPlayer(player2,playerr2);
            game.setPlayer(player2,playerr3);

            Ability::setUsingAbility(true);
            return true;
        } else {
            printPesan2("SWAP");
        }
    } else {
        printPesan("SWAP");
    }
    return false;
    
}