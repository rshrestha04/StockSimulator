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
#include "volume_inspector.hpp"



namespace csis3700{

    void volume_inspector::process_bar(const price_bar& b){
       
        last_volume = current_volume;
        current_volume= b.get_volume();
       
        
        if (last_volume > current_volume ){
            if ( volume_increase==0)volume_decrease++;
         
            if (volume_increase !=0) {
                 volume_decrease= 1;
                 volume_increase= 0;
             }
         }
     
        else if (current_volume > last_volume){
             if ( volume_decrease==0)volume_increase++;
         
            if (volume_decrease !=0) {
             volume_increase= 1;
             volume_decrease= 0;
            }
        }
        
        
         close_price = b.get_adjusted_close();
        
        
         
        
    }
        
    int volume_inspector::quantity_to_trade(double cash) const{
        
       
        
        if(volume_increase >2){
            if( cash/close_price > 4)
            return 4;
        }
         if(volume_decrease> 2){  
           return -held_shares;
        }
        
       
        return 0;
        
         
    }
        
    
    void volume_inspector::executed(const trade& t){
         
         if (t.is_buy())held_shares+= t.get_quantity();
       
         if(!t.is_buy()) held_shares=0;
            
         
    }
    void volume_inspector::rejected(const trade& t){
        if(!t.is_buy()) 
      std::cout<<"sell";
       assert(1>2);
        
    }
        
    
}
