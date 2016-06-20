void findPairs (Game g) {
    list hand = g->playerArray[whoseTurn-1].playerHand;
    link card = hand->head;
    //Holds the first matching card of a set
    link headCard = hand->head;
    //Used in the inner loop so as to not interfere with the flow
    //of the outer loop
    link pairCard = NULL;
    int cardVal;
    int same = TRUE;
    int count = 0;

    bubbleSort (hand);

    if (listLen(hand) >= 4) {
        //Outer loop to find each set of 4
        while (card->next != NULL) {
            headCard = card;
            cardVal = card->value;

            //Inner loop to check the next three values
            pairCard = card;
            while (same == TRUE && count < PAIR_SIZE &&
            pairCard->next != NULL) {
                if (cardVal == card->value) {
                    same = TRUE;
                    count++;
                } else {
                    same = FALSE;
                }
                pairCard = pairdCard->next;
            }

            if (count == PAIR_SIZE) {
                removePair (g, headCard);
            }

            card = pairCard;
        }
    }
}
