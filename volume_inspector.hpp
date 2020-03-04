/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   volume_inspector.hpp
 * Author: Ronish Shrestha
 *
 * Created on April 11, 2018, 9:57 PM
 */

#ifndef VOLUME_INSPECTOR_HPP
#define VOLUME_INSPECTOR_HPP
#include "trading_strategy.hpp"
#include "price_bar.hpp"
#include "simulator.hpp"
#include "trade.hpp"
#include <iostream>


namespace csis3700{

    class volume_inspector : public trading_strategy{
     private:
        int volume_increase;
        int volume_decrease;
        int last_volume;
        int current_volume;
        int close_price;
        int held_shares;
    
    public:
        volume_inspector():trading_strategy(){
            volume_increase=0;
            volume_decrease=0;
            close_price = 0;
            held_shares=0;
        }
        
        void process_bar(const price_bar& b);
        int quantity_to_trade(double cash) const;
        void executed(const trade& t);
        void rejected(const trade& t);
        
        
    }; 
}



#endif /* VOLUME_INSPECTOR_HPP */

