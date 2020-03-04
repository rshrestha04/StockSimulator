/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "it_cant_go_down_next.hpp"
#include "price_bar.hpp"
#include "simulator.hpp"
#include "trade.hpp"
#include <cassert>



namespace csis3700{

    void it_cant_go_down_next::process_bar(const price_bar& b){
       
        
       
        
        if (b.get_close() > b.get_open() ){
            if ( run_of_red==0)run_of_green++;
         
            if (run_of_red !=0) {
                 run_of_green= 1;
                 run_of_red= 0;
             }
         }
     
        else if (b.get_open() > b.get_close()){
             if ( run_of_green==0)run_of_red++;
         
            if (run_of_green !=0) {
             run_of_red= 1;
             run_of_green= 0;
            }
        }
        
        
         close_price = b.get_adjusted_close();
        
        
         
        
    }
        
    int it_cant_go_down_next::quantity_to_trade(double cash) const{
        
       
        
        if(run_of_red >4){
            if( cash/close_price > 4)
            return 4;
        }
         if(run_of_green>4){  
           return -held_shares;
        }
        
       
        return 0;
        
         
    }
        
    
    void it_cant_go_down_next::executed(const trade& t){
         
         if (t.is_buy())held_shares+= t.get_quantity();
       
         if(!t.is_buy()) held_shares=0;
            
         
    }
    void it_cant_go_down_next::rejected(const trade& t){
        if(!t.is_buy()) 
      std::cout<<"sell";
       assert(1>2);
        
    }
        
    
}

