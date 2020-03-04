/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "price_bar.hpp"
#include "simulator.hpp"
#include "trade.hpp"
#include <cassert>
#include <list>
#include "moving_average_cross.hpp"


namespace csis3700{
 
void moving_average::process_bar(const price_bar& b){
    
    lastprice=b.get_adjusted_close();
    if (lasttwenty.size()>= 20) lasttwenty.pop_front();
    lasttwenty.push_back(b.get_adjusted_close());
    
    if (lastfifty.size()>=50) lastfifty.pop_front();
    lastfifty.push_back(b.get_adjusted_close());
    
    if (lastfifty.size() ==50){
        totaltwenty=0;
        totalfifty=0;
        
        for (auto it= lasttwenty.begin();it!=lasttwenty.end();it++) totaltwenty+=*it;
       
        for (auto it= lastfifty.begin();it!=lastfifty.end();it++) totalfifty+=*it;
        
        averagetwenty=totaltwenty/20;
       // std::cout <<averagetwenty <<std::endl;
        averagefifty = totalfifty/50;
       // std::cout <<averagefifty <<std::endl;
    }
    
    
    
    
    
}
int moving_average::quantity_to_trade(double cash) const{
    if(!(lastfifty.size()==50))return 0;
    if (averagetwenty >= averagefifty &&  !buy){
        if(cash/lastprice>4)return 4;
        return 0;
    }
    
    if (averagefifty >= averagetwenty && !sell){
       
        return -held_shares;
    }
    return 0;
            
}
        void moving_average::executed(const trade& t){
          
         if (t.is_buy()){
             held_shares+= t.get_quantity(); 
             std::cout <<"i am here";
             buy=true;
             sell=false;
         }
         else{
             sell=true;
             buy= false;
             held_shares=0;
         }
        }
        void moving_average::rejected(const trade& t){
            std::cout<<"error"<<std::endl;
            assert(1>2);   
        }
}