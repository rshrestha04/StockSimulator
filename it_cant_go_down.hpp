/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   it_cant_go_down.hpp
 * Author: Ronish Shrestha
 *
 * Created on April 8, 2018, 7:30 PM
 */

#ifndef IT_CANT_GO_DOWN_HPP
#define IT_CANT_GO_DOWN_HPP
#include "trading_strategy.hpp"
#include "price_bar.hpp"
#include "simulator.hpp"
#include "trade.hpp"
#include <iostream>




namespace csis3700{
    

class it_cant_go_down : public csis3700::trading_strategy {
    private:
        int run_of_red;
        int run_of_green;
        int close_price;
        int days_passed;
    
    public:
        it_cant_go_down(): trading_strategy(){
            run_of_green=0;
            run_of_red=0;
            close_price = 0;
            days_passed= 0;
        }
        
        void process_bar(const price_bar& b);
        int quantity_to_trade(double cash);
        void executed(const trade& t);
        void rejected(const trade& t);
        
        
     
        
    
    
};
}
#endif /* IT_CANT_GO_DOWN_HPP */

