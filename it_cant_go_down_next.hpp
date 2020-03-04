/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   it_cant_go_down_next.hpp
 * Author: Ronish Shrestha
 *
 * Created on April 11, 2018, 8:40 PM
 */

#ifndef IT_CANT_GO_DOWN_NEXT_HPP
#define IT_CANT_GO_DOWN_NEXT_HPP
#include "trading_strategy.hpp"
#include "price_bar.hpp"
#include "simulator.hpp"
#include "trade.hpp"
#include <iostream>

namespace csis3700{

class it_cant_go_down_next :public trading_strategy{
     private:
        int run_of_red;
        int run_of_green;
        double close_price;
        
        int held_shares;
    
    public:
        it_cant_go_down_next():trading_strategy(){
            run_of_green=0;
            run_of_red=0;
            close_price = 0;
            held_shares=0;
        }
        
        void process_bar(const price_bar& b);
        int quantity_to_trade(double cash) const;
        void executed(const trade& t);
        void rejected(const trade& t);
        
        
     
        
    
};
}



#endif /* IT_CANT_GO_DOWN_NEXT_HPP */

