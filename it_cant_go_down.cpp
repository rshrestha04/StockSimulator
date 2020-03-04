/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "it_cant_go_down.hpp"
#include "price_bar.hpp"
#include "simulator.hpp"
#include "trade.hpp"



namespace csis3700{

    void it_cant_go_down::process_bar(const price_bar& b){
        if (b.get_close() > b.get_open() ){
            if ( run_of_red==0)run_of_green++;
         
            if (run_of_red !=0) {
                 run_of_green= 1;
                 run_of_red= 0;
             }
         }
     
        else if (b.get_open() > b.get_close() and run_of_green=0){
             if ( run_of_green==0)run_of_red++;
         
            if (run_of_green !=0) {
             run_of_red= 1;
             run_of_green= 0;
            }
        }
        
        
         close_price = b.get_adjusted_close();
         days_passed++;
    }
        
    int it_cant_go_down::quantity_to_trade(double cash){
        
        if(days_passed==10){
            days_passed=0;
            return -held_shares;
        }
        
        if(run_of_red >3){
            int buy=10;
            return buy;
        }
        
       
        
    }
        
    
}

