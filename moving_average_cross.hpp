/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   moving_average_cross.hpp
 * Author: Ronish Shrestha
 *
 * Created on April 11, 2018, 2:17 PM
 */

#ifndef MOVING_AVERAGE_CROSS_HPP
#define MOVING_AVERAGE_CROSS_HPP
#include "trading_strategy.hpp"
#include "price_bar.hpp"
#include "simulator.hpp"
#include "trade.hpp"
#include <iostream>
#include <list>

namespace csis3700{

class moving_average : public trading_strategy{
    private:
        std::list<double> lasttwenty;
        std::list<double> lastfifty;
        double averagetwenty, averagefifty, totaltwenty, totalfifty,lastprice;
        bool sell,buy;
        int held_shares;
    public:
        moving_average(){
            averagetwenty=0;
            averagefifty=0;
            totaltwenty=0;
            totalfifty=0;
            sell=true;
            buy=false;
            held_shares= 0;
            lastprice=0;
        } 
        void process_bar(const price_bar& b);
        int quantity_to_trade(double cash) const;
        void executed(const trade& t);
        void rejected(const trade& t);
            
    
};

}




#endif /* MOVING_AVERAGE_CROSS_HPP */

