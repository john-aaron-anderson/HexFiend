//
//  HFByteRangeAttributeArray.h
//  HexFiend_2
//
//  Created by Peter Ammon on 8/24/09.
//  Copyright 2009 ridiculous_fish. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface HFByteRangeAttributeArray : NSObject <NSMutableCopying> {
}

/*! Returns the set of attributes at the given index, and the length over which those attributes are valid (if not NULL). */
- (NSSet *)attributesAtIndex:(unsigned long long)index length:(unsigned long long *)length;

/*! Returns the set of attributes within the given range. */
- (NSSet *)attributesInRange:(HFRange)range;

/*! Returns the first range of a given attribute.  If it is not present, returns {ULLONG_MAX, ULLONG_MAX} */
- (HFRange)rangeOfAttribute:(NSString *)attribute;

/*! Adds a given attribute for a given range. */
- (void)addAttribute:(NSString *)attributeName range:(HFRange)range;

/*! Removes the given attribute within the given range. */
- (void)removeAttribute:(NSString *)attributeName range:(HFRange)range;

/*! Removes the given attribute entirely. */
- (void)removeAttribute:(NSString *)attributeName;

/*! Removes the given attributes entirely. */
- (void)removeAttributes:(NSSet *)attributeName;

/*! Returns whether the receiver is empty.  This should be a count instead. */
- (BOOL)isEmpty;

/*! Returns an NSEnumerator of the attributes.  The attributes are returned in order, but there is no way to get the range of each attribute. */
- (NSEnumerator *)attributeEnumerator;
 
/*! Transfer attributes in the given range from array, adding baseOffset to each attribute range. range is interpreted as a range in array. */
- (void)transferAttributesFromAttributeArray:(HFByteRangeAttributeArray *)array range:(HFRange)range baseOffset:(unsigned long long)baseOffset;

@end

@interface HFNaiveByteRangeAttributeArray : HFByteRangeAttributeArray {
    NSMutableArray *attributeRuns;
}
@end

@class HFAnnotatedTree;
@interface HFAnnotatedTreeByteRangeAttributeArray : HFByteRangeAttributeArray {
    HFAnnotatedTree *atree;
    NSMutableDictionary *attributesToNodes;
}
@end