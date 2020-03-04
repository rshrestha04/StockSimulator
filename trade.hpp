#ifndef __CDS_TRADE_H
#define __CDS_TRADE_H
#include <string>

namespace csis3700 {
  class trade {
  public:

    /**
     * A trade at the specified date/time, at the specified price, for
     * the specified quantity.  If buy is true then this is a buy
     * trade, otherwise it is a sell.
     */
    trade(std::string date_time, double price, double quantity, bool buy){
         
    }

    /**
     * Returns the price at which this trade was excecuted.
     */
    double get_price() const { return price; }

    /**
     * Return true if this is a buy (false otherwise).
     */
    bool is_buy() const { return buy; }

    /**
     * Return the number of shares bought or sold.
     */
    double get_quantity() const { return quantity; }

    /**
     * Return the net credit to account cash.  For buy trades this
     * will be a negative number and for sell trades it will be
     * positive.
     */
    double get_net_credit() const{
        if (buy){
            return -(price*quantity);
        }
        
        if (!buy){
            return (price*quantity);
        }
    }

    std::string get_date_time() const{return date_time;}
    
  private:
    std::string date_time;
    double price;
    double quantity;
    bool buy;
  };
}

#endif
