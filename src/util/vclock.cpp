/*
 * Copyright (C) 2014  Maxim Noah Khailo
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * In addition, as a special exception, the copyright holders give 
 * permission to link the code of portions of this program with the 
 * Botan library under certain conditions as described in each 
 * individual source file, and distribute linked combinations 
 * including the two.
 *
 * You must obey the GNU General Public License in all respects for 
 * all of the code used other than Botan. If you modify file(s) with 
 * this exception, you may extend this exception to your version of the 
 * file(s), but you are not obligated to do so. If you do not wish to do 
 * so, delete this exception statement from your version. If you delete 
 * this exception statement from all source files in the program, then 
 * also delete it here.
 */

#include "util/vclock.hpp"

namespace fire 
{
    namespace util 
    {
        dict to_dict(const sclock& cs)
        {
            dict d;
            for(const auto& c : cs)
                d[c.first] = c.second;
            return d;
        }

        sclock to_sclock(const dict& d)
        {
            sclock c;
            for(const auto& v : d)
                c[v.first] = v.second.as_size();
            return c;
        }

        dict to_dict(const tracked_sclock& c)
        {
            dict d;
            d["i"] = c.id();
            d["v"] = to_dict(c.clock());
            return d;
        }

        tracked_sclock to_tracked_sclock(const dict& d)
        {
            auto id = d["i"].as_string();
            tracked_sclock c{
                d["i"].as_string(), 
                to_sclock(d["v"].as_dict())
            };
            return c;
        }
    }
}
