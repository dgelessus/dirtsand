/******************************************************************************
 * This file is part of dirtsand.                                             *
 *                                                                            *
 * dirtsand is free software: you can redistribute it and/or modify           *
 * it under the terms of the GNU General Public License as published by       *
 * the Free Software Foundation, either version 3 of the License, or          *
 * (at your option) any later version.                                        *
 *                                                                            *
 * dirtsand is distributed in the hope that it will be useful,                *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * GNU General Public License for more details.                               *
 *                                                                            *
 * You should have received a copy of the GNU General Public License          *
 * along with dirtsand.  If not, see <http://www.gnu.org/licenses/>.          *
 ******************************************************************************/

#ifndef _MOUL_NETMSGGROUPOWNER_H
#define _MOUL_NETMSGGROUPOWNER_H

#include "NetMessage.h"
#include "Key.h"

struct stat;
namespace MOUL
{
    struct NetGroupId
    {
        enum
        {
            e_NetGroupConstant = (1<<0),
            e_NetGroupLocal    = (1<<1),
        };

        Location m_location;
        uint8_t m_flags;

        NetGroupId() : m_location(Unknown.m_location), m_flags(Unknown.m_flags) { }

        NetGroupId(const Location& location, uint8_t flags)
            : m_location(location), m_flags(flags) { }

        static NetGroupId Unknown;
        static NetGroupId LocalPlayer;
        static NetGroupId RemotePlayer;
        static NetGroupId LocalPhysicals;
        static NetGroupId RemotePhysicals;
    };

    class NetMsgGroupOwner : public NetMsgServerToClient
    {
        FACTORY_CREATABLE(NetMsgGroupOwner)

    public:
        struct GroupInfo
        {
            NetGroupId m_group;
            bool m_own;
        };

        std::vector<GroupInfo> m_groups;

        virtual void read(DS::Stream* stream);
        virtual void write(DS::Stream* stream);

    protected:
        NetMsgGroupOwner(uint16_t type) : NetMsgServerToClient(type) { }
    };
}

#endif
