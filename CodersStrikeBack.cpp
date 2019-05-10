#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;        

struct Coordinate{
    int x_, y_;
    void Init(void){
        x_ = -1;
        y_ = -1;
    }
};

int Distance(Coordinate c1, Coordinate c2){
    return int(abs(sqrt(pow((c1.x_ - c2.x_), 2) + pow((c1.y_ - c2.y_),2))));
}

struct Player{
    bool boost_;
    int thrust_;
    Coordinate coordinate_;
    Coordinate lastCoordinate_;
    
    void Init(void){
        coordinate_.Init();
        thrust_ = -1;
        boost_ = true;
    }
    
    void Update(void){
        lastCoordinate_ = coordinate_;
        cin >> coordinate_.x_ >> coordinate_.y_;
    }
};

struct Checkpoint{
    Coordinate coordinate_;
    int distance_, angle_;
    
    void Init(void){
        coordinate_.Init();
        distance_ = -1;
        angle_ = -181;
    }
    
    void Update(void){
        cin >> coordinate_.x_ >> coordinate_.y_ >> distance_ >> angle_;
        cin.ignore();
    }
};

class Game{
    public:
        void Init(void);
        void Update(void);
        void Move(void);
    private:
        Player player_[2];
        Checkpoint checkpoint_;
};

void Game::Init(void){    
    player_[0].Init();
    player_[1].Init();
    checkpoint_.Init();
}

void Game::Update(void){
    player_[0].Update();
    checkpoint_.Update();
    cin >> player_[1].coordinate_.x_ >> player_[1].coordinate_.y_;
    cin.ignore();
}

void Game::Move(void){    
    
    Coordinate move;
    move.Init();
    move.x_ = checkpoint_.coordinate_.x_;
    move.y_ = checkpoint_.coordinate_.y_;

    player_[0].thrust_ = 100;
    
    if(player_[0].boost_ == true && checkpoint_.angle_ < 30 && checkpoint_.angle_ > -30 && checkpoint_.distance_ > 6000){
        player_[0].thrust_ = -2;
        player_[0].boost_ = false;
    }    
    
    if(Distance(player_[0].coordinate_, player_[1].coordinate_) < 2000){
        move.x_ = player_[1].coordinate_.x_;
        move.y_ = player_[1].coordinate_.y_;
    }
    
    if((checkpoint_.angle_ > 90 || checkpoint_.angle_ < -90) && (checkpoint_.distance_ > 6000 || checkpoint_.distance_ < 3000)){
        player_[0].thrust_ = abs(int(cos(checkpoint_.angle_) * 70) + 30);
    }
    
    cout << move.x_ << " " << move.y_ << " ";
    
    if(player_[0].thrust_ == -2){
        cout << "BOOST" << endl;
    }else{    
        cout << std::to_string(player_[0].thrust_) << endl;
    }
}

int main()
{
    Game game;   
    game.Init();
    
    while(true) {
        game.Update();
        game.Move();
    }
}
