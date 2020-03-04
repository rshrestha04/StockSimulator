#ifndef __CDS_SIMULATOR_H
#define __CDS_SIMULATOR_H
#include <istream>
#include <vector>
#include "price_bar.hpp"
#include "trade.hpp"
#include "trading_strategy.hpp"
#include "it_cant_go_down.hpp"
#include <fstream>
#include <string>
#include <algorithm>
#include <stdlib.h>

namespace csis3700 {
  class simulator {
  public:
    /**
     * Create a simulator that makes trading decisions using the
     * supplied trading strategy.  The simulator will start the
     * account with the specified balance of cash.
     */
    simulator(trading_strategy* s, double balance){
        strategy = s;
        shares_held=0;
        cash = balance;
        last_price=0;
        
    }

    /**
     * Read price_bars from the supplied stream.  Note that the first
     * line of the stream will be a header and should be ignored.
     * Subsequent lines will be formatted:
     *   date/time open high low close volume adjusted_close
     *
     * Data in the stream will be in reverse chronological order.
     *
     * This method should populate the bars collection with bars
     * created from the contents of this stream.
     *
     * If reverse is true, the stream is in reverse chronological
     * order (in which case you must reverse the order of the data
     * when placing it in your bars collection).  If reverse if false,
     * the data is in chronological order.
     *
     */
    void read_bars(std::istream& is, bool reverse){
        
        std::string data;
        if (!is.good()){
            return;
        }
        
        
        getline(is,data);
        std::string date;
        double open, high, low, close, volume, adjusted_close;
        
        while (is >>date>> open>>high>>close>>volume>>adjusted_close){
        price_bar bar(open,high,low,close,adjusted_close,volume);
        bars.push_back(bar); 
        }
        
        if(reverse){
            reverse(bars.begin(),bars.end());
        } 
        
        
        
        
        
        
        
        
        
        
    }

    /**
     * Perform the simulation by iterating through each bar with the
     * following steps:
     *    
     * 1) tell the strategy to process the bar 
     *
     * 2) ask the strategy how many shares it wants to trade
     *
     * 3) if there is enough cash in the account and the trade matches the
     *    current position (cannot sell more than you are holding)
     *   3a) create a trade object,
     *   3b) inform that strategy (trade_executed()) that a trade was executed,
     *   3c) update the cash available,
     *   3d) add the trade to the trades collection
     *
     */
    void run(){
        for(auto it=bars.begin();it!=bars.end(); it++){
            last_price= it->get_adjusted_close();
           
            
            
            
            strategy->process_bar(it*);
            
            int trade;
            trade=strategy->quantity_to_trade(cash);
            if(trade >0 ){
                if( trade*last_price<= cash){
                    trade buy(it->get_date_time(),last_price,trade,true);
                    strategy->executed(buy);
                    shares_held+=trade;
                    cash-= last_price*trade;
                    trades.push_back(buy);   
                }
                else {
                    trade buy(it->get_date_time(),last_price,trade,true);
                    strategy->rejected(buy);
                }
            }
            
            if(trade<0){
                if( abs(trade) <=shares_held){
                    trade sell(it->get_date_time(),last_price,abs(trade),false );
                    strategy->executed(sell);
                    shares_held-= trade;
                    cash+= last_price*trade;
                    trades.push_back(sell);
                }
                
                else {
                    trade sell(it->get_date_time(),last_price,abs(trade),false );
                    strategy->rejected(sell);
                }
                
                
            }
            
            
        }
    }

    std::vector<trade> get_trades() const { return trades; }

    /**
     * Return the current account equity (cash plus holdings value).
     */
    double get_equity() const{return cash+(shares_held*last_price);}

    /**
     * Return the number of shares held by this trading strategy.
     */
    double get_shares_held() const{return shares_held;}

    
    std::vector<price_bar> get_bars() const { return bars; }

    
  private:
    trading_strategy* strategy;
    double cash;
    std::vector<price_bar> bars;
    std::vector<trade> trades;
    int shares_held;
    double last_price;
  };
}

#endif
