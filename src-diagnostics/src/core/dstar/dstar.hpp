/**
 * @file dstar.hpp
 * @brief This implements the source code definitions descriped in `dstar.cpp`
 * TODO: UPDATE
 */

#ifndef DIAGNOSTICS_SRC_CORE_SPI_DSTAR_H_
#define DIAGNOSTICS_SRC_CORE_SPI_DSTAR_H_

#include <stdint.h>


/** @def DS_HEADER_IDENTN
 *  @brief Total count of dstar identifiers.
 */
#define DS_HEADER_IDENTN 16

/** @def DS_SPI_HEADER_DATEN
 *  @brief Total count of date characters.
 */
#define DS_SPI_HEADER_DATEN 8


/** @enum DStarErrorKind
 *  @brief ErrorKind definition for the DStar protocol.
 */
enum class DStarErrorKind
{
    /**
     * @brief No errors were discovered during processing.
     */
    Success=0,
};

/** @enum DSIdentKind
 *  @brief Identifier definitions for each DStarHeader identifier value.
 * 
 *         Each enumerator is directly converted into a value associated with an index
 *         applicable to a DStarHeader.ident value.
 * 
 *  @example
 * 
 *  ```C++
 *      {
 *          // Returns the identifier: "MagicNumber0", or the 1st magic number.
 *          DStarHeader.ident[DSIdentKind::MagicNumber0];
 *      }
 *  ```
 */
enum class DSIdentKind
{
    MagicNumber0=0, /** < DStar Magic Number 0th index. Typically 'D' */
    MagicNumber1,   /** < DStar Magic Number 1st index. Typically 'S' */
    MagicNumber2,   /** < DStar Magic Number 2nd index. Typically 'T' */
    MagicNumber3,   /** < DStar Magic Number 3rd index. Typically 'A' */
    MagicNumebr4,   /** < DStar Magic Number 4th index. Typically 'R' */
    Type,           /** < DStar Protocol Type */
};

/** @enum DSKind
 *  @brief The DStar protocol type (and associated static header) we are expecting.
 */
enum class DSKind
{
    SPI=0 /** < Diagnostics spi header is expected next */
};

/** @enum DStarLevelKind
 * 
 */
enum class DStarLevelKind
{
    Info=0,         /** < Some operating information */
    Warning,        /** < Information that implies a workable fault */
    Error,          /** < Information that implies a resetable fault */
    Catastrophic    /** < Information that implies a non-resetable fault */
};


/** @struct DStarHeader
 *  @brief TODO: DOCS
 */
__attribute__((packed)) struct DStarHeader
{
    /**
     * @brief Identifier array.
     * 
     *        Each index of the identier (max DS_HEADER_IDENTN) has special value and is
     *        documented in the associated DSIdentKind. For more information, see the
     *        protocol specification.
     * 
     * @see DSIdentKind - DS Header Identifiers
     */
    uint8_t ident[DS_HEADER_IDENTN];

    /**
     * @brief Source address.
     * 
     *        This is the address defined by the original sender of the header. It does
     *        not change from forward-to-forward operation.
     * 
     *        The identifer is fundamentally meaningless prior to manual assignment by an
     *        operator. It's primarily used so we know who is transmitting.
     */
    uint16_t src;

    /**
     * @brief Destination address.
     * 
     *        This is the address defined by manual operators of which we are attempting
     *        to send to. Used in protocol automation via a router.
     */
    uint16_t dst;
};


/** @struct DStarPayloadHeader
 *  @brief TODO: DOCS
 */
__attribute__((packed)) struct DStarSPIHeader
{
    /**
     * @brief Date that the message was sent.
     * 
     *        Format of YYYYMMDD. Each element is a single character.
     */
    const uint8_t date[DS_SPI_HEADER_DATEN];

    /**
     * @brief One of several DStar diagnostics levels.
     * 
     * @see DStarLevelKind
     */
    const DStarLevelKind logLevel;

    /**
     * @brief The dynamic length of the diagnostics payload.
     * 
     *        Variable because it is technically possible to send a single header followed
     *        by many transmissions.
     */
    uint32_t payloadSize;
};


/** @class DStarSerializer
 *  @brief Serializer / Deserializer for the DStar protocol.
 */
class DStarSerializer
{
  public:
    /**
     * @brief DStarSerializer constructor.
     */
    DStarSerializer() = delete;

    /**
     * @brief Deleted copy constructor.
     */
    DStarSerializer(const DStarSerializer&)=delete;

    /**
     * @brief Deleted assignment operator.
     */
    DStarSerializer operator=(const DStarSerializer&) = delete;

    /**
     * @brief TODO
     */
    static DStarErrorKind serialize(const uint8_t *bytes, const uint64_t N)
    {
    }
};


#endif  // DIAGNOSTICS_SRC_CORE_SPI_DSTAR_H_
