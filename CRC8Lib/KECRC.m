//
//  KECRC.m
//  CRC8Lib
//
//  Created by cj on 9/30/14.
//  Copyright (c) 2014 KickinEspresso. All rights reserved.
//

#import "KECRC.h"

@implementation KECRC

- (int)crc8Checksum:(NSString*)dataFrame{
    
    char j;
    int crc8 = 0;
    int x = 0;
    
    for (int i = 0; i < [dataFrame length]; i++){
        x = [dataFrame characterAtIndex:i]; //x is concerted to ascii
        
        for (int k = 0; k < 8; k++){
            j = 1 & (x ^ crc8);
            crc8 = floor0(crc8 / 2) & 0xFF;
            x = floor0(x / 2) & 0xFF;
            if (j != 0 ){
                crc8 = crc8 ^ 0x8C;
            }
        }
    }
    return crc8;
}

int floor0( double value ){
    if (value < 0.0)
        return (int)ceil( value );
    else
        return (int)floor( value );
}

@end
