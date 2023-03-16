#include "Abilityless.hpp"


Abilityless::Abilityless() : Ability::Ability(7){

}
bool Abilityless::useAbility(Game<Card>& game, int playerAbility, int player){
    bool allUse;
    int count = 0;
    for(int i=0;i<game.getPlayers().size();i++){
        if(player != i){
            if(game.getPlayer(i).getAbility()<=0){
                count++;
            }
        }
    }
    if(count == game.getPlayers().size()-1){
        allUse = true;
    }else{
        allUse = false;
    }
    if (playerAbility == 7 || playerAbility == 0 || playerAbility == -7){
        if (playerAbility == 7){
            if(!allUse){
                cout<< game.getPlayer(player).getName()<<" akan mematikan kartu ablity lawan!"<<endl;
                cout<<"Silahkan pilih pemain yang kartu abilitynya ingin dimatikan: "<<endl;
                Player Playermati, playerPengguna;
                for(int i=0;i<game.getPlayers().size();i++){
                    if(i != player){
                        cout<< i+1 <<". " << game.getPlayer(i).getName()<<endl;
                    }
                }

                cout<<">";
                int enemyNumber;
                Input(enemyNumber);
                enemyNumber--;
                Playermati = game.getPlayer(enemyNumber);
                playerPengguna = game.getPlayer(player);
                if(game.getPlayer(enemyNumber).getAbility()>0){
                    Playermati.setAbility(0);
                    cout<<"Kartu ability " << game.getPlayer(enemyNumber).getName() <<" telah dimatikan."<<endl;
                    game.setPlayer(enemyNumber,Playermati);
                    playerPengguna.setAbility(-1);
                    game.setPlayer(player,playerPengguna);
                }else{
                    cout<<"Kartu ability "<< game.getPlayer(enemyNumber).getName() <<" telah dipakai sebelumnya. Yah, sayang penggunaan kartu ini sia-sia"<<endl;
                    playerPengguna.setAbility(-7);
                    game.setPlayer(player,playerPengguna);
                }
                Ability::setUsingAbility(true);
            }else{
                cout<<"Eits, ternyata semua pemain sudah memakai kartu kemampuan. Yah kamu kena sendiri deh, kemampuanmu menjadi abilityless. Yah, pengunaan kartu ini sia-sia"<<endl;
            }
            return true;
            
        } else if(playerAbility ==-7) {
            printPesan2("ABILITYLESS");
        } else if(playerAbility == 0){
            printPesan2("ABILITYLESS");
        }
    } else {
        printPesan("ABILITYLESS");
    }
    return false;
    
}