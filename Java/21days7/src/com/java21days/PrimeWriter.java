/*
 * Sams TeachYourself Java in 21 days all rights reserved.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.java21days;

import java.io.*;
      
public class PrimeWriter {
    public static void main(String[] args){
        int[] primes = new int[400];
        int numPrimes = 0;
        // candidate: the number that might be prime
        int candidate = 2;
        while (numPrimes < 400) {
            if (isPrime(candidate)){
                primes[numPrimes] = candidate;
                numPrimes++;
            }
            candidate++;
        }
    }
}
