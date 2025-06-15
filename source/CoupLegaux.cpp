#include "CoupLegaux.hpp"

CoupLegaux::CoupLegaux()
{
}

void CoupLegaux::allCoupLegaux()
{
    std::vector<std::pair<int, int>> temp;
    this->_coupLegauxBlanc.clear();
    this->_coupLegauxNoir.clear();
    this->_coupParPiece.clear();
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(this->_echiquier.getCase(i,j)=='C'){
                temp = getCoupCavalier(i,j,'B');
                this->_coupLegauxBlanc.insert(this->_coupLegauxBlanc.end(), temp.begin(), temp.end());
            }else if(this->_echiquier.getCase(i,j)=='c'){
                temp = getCoupCavalier(i, j, 'n');
                this->_coupLegauxNoir.insert(this->_coupLegauxBlanc.end(), temp.begin(), temp.end());
            }else if(this->_echiquier.getCase(i,j)=='t'){
                temp = getCoupTour(i,j, 'n');
                this->_coupLegauxNoir.insert(this->_coupLegauxBlanc.end(), temp.begin(), temp.end());
            }else if(this->_echiquier.getCase(i,j)=='T'){
                temp = getCoupTour(i,j,'B');
                this->_coupLegauxBlanc.insert(this->_coupLegauxBlanc.end(), temp.begin(), temp.end());
            }else if(this->_echiquier.getCase(i,j)=='F'){
                temp = getCoupFou(i,j,'B');
                this->_coupLegauxBlanc.insert(this->_coupLegauxBlanc.end(), temp.begin(), temp.end());
            }else if(this->_echiquier.getCase(i,j)=='f'){
                temp = getCoupFou(i,j, 'n');
                this->_coupLegauxNoir.insert(this->_coupLegauxBlanc.end(), temp.begin(), temp.end());
            }else if(this->_echiquier.getCase(i,j)=='D'){
                temp = getCoupDame(i, j, 'B');
                this->_coupLegauxBlanc.insert(this->_coupLegauxBlanc.end(), temp.begin(), temp.end());
            }else if(this->_echiquier.getCase(i,j)=='d'){
                temp = getCoupDame(i, j, 'n');
                this->_coupLegauxNoir.insert(this->_coupLegauxBlanc.end(), temp.begin(), temp.end());
            }else if(this->_echiquier.getCase(i,j)=='R'){
                temp = getCoupRoi(i, j, 'B');
                this->_coupLegauxBlanc.insert(this->_coupLegauxBlanc.end(), temp.begin(), temp.end());
            }else if(this->_echiquier.getCase(i,j)=='r'){
                temp = getCoupRoi(i, j, 'n');
                this->_coupLegauxNoir.insert(this->_coupLegauxBlanc.end(), temp.begin(), temp.end());
            }else if(this->_echiquier.getCase(i,j)=='P'){
                temp = getCoupPion(i, j, 'B');
                this->_coupLegauxBlanc.insert(this->_coupLegauxBlanc.end(), temp.begin(), temp.end());
            }else if(this->_echiquier.getCase(i,j)=='p'){
                temp = getCoupPion(i, j, 'n');
                this->_coupLegauxNoir.insert(this->_coupLegauxBlanc.end(), temp.begin(), temp.end());
            }
        }
    }
}

std::vector<std::pair<int, int>> CoupLegaux::getCoupCavalier(int lettre, int numero, char couleur) const
{
    std::pair<int, int> temp;
    std::vector<std::pair<int, int>> coupCavalier;
    temp.first=lettre+2;
    temp.second=numero+1;
    if(lettre<8&&lettre>=0&&numero<8&&numero>=0)
    coupCavalier.push_back(temp);
    temp.first=lettre+2;
    temp.second=numero-1;
    if(lettre<8&&lettre>=0&&numero<8&&numero>=0)
    coupCavalier.push_back(temp);
    temp.first=lettre-2;
    temp.second=numero+1;
    if(lettre<8&&lettre>=0&&numero<8&&numero>=0)
    coupCavalier.push_back(temp);
    temp.first=lettre-2;
    temp.second=numero-1;
    if(lettre<8&&lettre>=0&&numero<8&&numero>=0)
    coupCavalier.push_back(temp);
    temp.first=lettre+1;
    temp.second=numero+2;
    if(lettre<8&&lettre>=0&&numero<8&&numero>=0)
    coupCavalier.push_back(temp);
    temp.first=lettre+1;
    temp.second=numero-2;
    if(lettre<8&&lettre>=0&&numero<8&&numero>=0)
    coupCavalier.push_back(temp);
    temp.first=lettre-1;
    temp.second=numero-2;
    if(lettre<8&&lettre>=0&&numero<8&&numero>=0)
    coupCavalier.push_back(temp);
    temp.first=lettre-1;
    temp.second=numero+2;
    if(lettre<8&&lettre>=0&&numero<8&&numero>=0)
    coupCavalier.push_back(temp);
    int i = 0;
    if(couleur=='B'){
        while(i<coupCavalier.size())
        {
            if(this->_echiquier.getCase(coupCavalier[i].first, coupCavalier[i].second)=='F,C,D,R,P,T'){
                coupCavalier.erase(coupCavalier.begin() + i);
                i--;
            }
            i++;
        }
    }
    else{
        while(i<coupCavalier.size())
        {
            if(this->_echiquier.getCase(coupCavalier[i].first, coupCavalier[i].second)=='f,c,d,r,p,t'){
                coupCavalier.erase(coupCavalier.begin() + i);
                i--;
            }
            i++;
        }
    }
    
    return coupCavalier;
}

std::vector<std::pair<int, int>> CoupLegaux::getCoupTour(int lettre, int numero, char couleur) const
{
    std::pair<int, int> temp;
    bool lettreposs=true;
    bool numeroposs=true;
    std::vector<std::pair<int, int>> coupTour;
    for(int i=0; i<8; i++){
        if(i<lettre&&this->_echiquier.getCase(i,numero)!='v'&&lettreposs==true){
            coupTour.erase(coupTour.begin(),coupTour.end());  
        }
        else if(i<numero&&this->_echiquier.getCase(lettre, i)!='v'&&numeroposs==true){
            coupTour.erase(coupTour.begin(),coupTour.end()); 
        }
        if(couleur=='B'&&this->_echiquier.getCase(i,numero)!='T,C,D,R,P,F'&&lettreposs==true){
            temp.first=i;
            temp.second=numero;
            coupTour.push_back(temp);
        }
        else if(this->_echiquier.getCase(i,numero)!='t,c,d,r,p,f'&&lettreposs==true){
            temp.first=i;
            temp.second=numero;
            coupTour.push_back(temp);
        }
        if(couleur=='B'&&this->_echiquier.getCase(lettre, i)!='T,C,D,R,P,F'&&numeroposs==true){
            temp.first=i;
            temp.second=numero;
            coupTour.push_back(temp);
        }
        else if(this->_echiquier.getCase(lettre, i)!='t,c,d,r,p,f'&&numeroposs==true){
            temp.first=i;
            temp.second=numero;
            coupTour.push_back(temp);
        }
        if(i>lettre&&this->_echiquier.getCase(i, numero)!='v'&&lettreposs==true){
            lettreposs=false;
        }
        if(i>numero&&this->_echiquier.getCase(lettre, i)!='v'&&numeroposs==true){
            numeroposs=false;
        }
    } 
    return coupTour;
}

std::vector<std::pair<int, int>> CoupLegaux::getCoupFou(int lettre, int numero, char couleur) const
{
    std::pair<int, int> temp;
    std::vector<std::pair<int, int>> coupFou;
    int i = lettre+1;
    int j = numero+1;
    while(i<8&&j<8){
        if(couleur=='B'&&this->_echiquier.getCase(i,j)!='F,R,T,C,D,P'){
            temp.first=i;
            temp.second=j;
            coupFou.push_back(temp);       
        }
        else if(this->_echiquier.getCase(i,j)!='f,r,t,c,d,p'){
            temp.first=i;
            temp.second=j;
            coupFou.push_back(temp);
        }
        if(this->_echiquier.getCase(i,j)!='v'){
            break;
        }
        i++;
        j++;
    }

    int i = lettre+1;
    int j = numero-1;
    while(i<8&&j>=0){
        if(couleur=='B'&&this->_echiquier.getCase(i,j)!='F,R,T,C,D,P'){
            temp.first=i;
            temp.second=j;
            coupFou.push_back(temp);       
        }
        else if(this->_echiquier.getCase(i,j)!='f,r,t,c,d,p'){
            temp.first=i;
            temp.second=j;
            coupFou.push_back(temp);
        }
        if(this->_echiquier.getCase(i,j)!='v'){
            break;
        }
        i++;
        j++;
    }

    int i = lettre-1;
    int j = numero+1;
    while(i>=0&&j<8){
        if(couleur=='B'&&this->_echiquier.getCase(i,j)!='F,R,T,C,D,P'){
            temp.first=i;
            temp.second=j;
            coupFou.push_back(temp);       
        }
        else if(this->_echiquier.getCase(i,j)!='f,r,t,c,d,p'){
            temp.first=i;
            temp.second=j;
            coupFou.push_back(temp);
        }
        if(this->_echiquier.getCase(i,j)!='v'){
            break;
        }
        i++;
        j++;
    }

    int i = lettre-1;
    int j = numero-1;
    while(i>=0&&j>=0){
        if(couleur=='B'&&this->_echiquier.getCase(i,j)!='F,R,T,C,D,P'){
            temp.first=i;
            temp.second=j;
            coupFou.push_back(temp);       
        }
        else if(this->_echiquier.getCase(i,j)!='f,r,t,c,d,p'){
            temp.first=i;
            temp.second=j;
            coupFou.push_back(temp);
        }
        if(this->_echiquier.getCase(i,j)!='v'){
            break;
        }
        i++;
        j++;
    }
    return coupFou;
}

std::vector<std::pair<int, int>> CoupLegaux::getCoupDame(int lettre, int numero, char couleur) const
{
    std::vector<std::pair<int, int>> coupDame;
    std::vector<std::pair<int, int>> temp;
    coupDame = getCoupTour(lettre, numero, couleur);
    temp = getCoupFou(lettre, numero, couleur);
    coupDame.insert(coupDame.end(), temp.begin(), temp.end());
    return coupDame;
}

std::vector<std::pair<int, int>> CoupLegaux::getCoupRoi(int lettre, int numero, char couleur) const
{
    std::pair<int, int> temp;
    std::vector<std::pair<int, int>> coupRoi;

    if(couleur=='B'){
        for(int i=lettre-1; i<lettre+2; i++){
            for(int j=numero-1; j<numero+2; j++){
                if(i>=0&&i<8&&j>=0&&j<8&&this->_echiquier.getCase(i,j)!='F,D,T,C,P'){
                    temp.first=i;
                    temp.second=j;
                    if(i!=lettre||j!=numero)
                    coupRoi.push_back(temp);
                }
            }
        }
    }
    else{
        for(int i=lettre-1; i<lettre+2; i++){
            for(int j=numero-1; j<numero+2; j++){
                if(i>=0&&i<8&&j>=0&&j<8&&this->_echiquier.getCase(i,j)!='f,d,t,c,p'){
                    temp.first=i;
                    temp.second=j;
                    if(i!=lettre||j!=numero)
                    coupRoi.push_back(temp);
                }
            }
        }
    }
    
    return coupRoi;
}

std::vector<std::pair<int, int>> CoupLegaux::getCoupPion(int lettre, int numero, char couleur) const
{
    std::pair<int, int> temp;
    std::vector<std::pair<int, int>> coupPion;
    if(couleur=='B'||couleur=='b'){
        if(this->_echiquier.getCase(lettre, numero+1)=='v'){
            temp.first=lettre;
            temp.second=numero+1;
            coupPion.push_back(temp);
            if(numero==1&&this->_echiquier.getCase(lettre, numero+2)=='v'){
                temp.second++;
                coupPion.push_back(temp);
            }
        }
        if(lettre!=0){
            if(this->_echiquier.getCase(lettre-1, numero+1)=='p,d,t,f,c'){
                temp.first=lettre-1;
                temp.second=numero+1;
                coupPion.push_back(temp);
            }
        }
        if (lettre!=7){
            if(this->_echiquier.getCase(lettre+1, numero+1)=='p,d,t,f,c'){
                temp.first=lettre+1;
                temp.second=numero+1;
                coupPion.push_back(temp);
            }
        }
    }
    else{
        if(this->_echiquier.getCase(lettre, numero-1)=='v'){
            temp.first=lettre;
            temp.second=numero-1;
            coupPion.push_back(temp);
            if(numero==1&&this->_echiquier.getCase(lettre, numero-2)=='v'){
                temp.second--;
                coupPion.push_back(temp);
            }
        }
        if(lettre!=0){
            if(this->_echiquier.getCase(lettre-1, numero-1)=='P,D,T,F,C'){
                temp.first=lettre-1;
                temp.second=numero-1;
                coupPion.push_back(temp);
            }
        }
        if (lettre!=7){
            if(this->_echiquier.getCase(lettre+1, numero-1)=='P,D,T,F,C'){
                temp.first=lettre+1;
                temp.second=numero-1;
                coupPion.push_back(temp);
            }
        }
    }
    return coupPion;
}
