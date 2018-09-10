#if defined _limit_ban_included
  #endinput
#endif
#define _limit_ban_included

#define MAX_BAN_DURATIONS 32

/*********************************************************
 * Returns the current number of defined ban lengths.
 *
 * @return		The number of ban lengths defined.
 *********************************************************/
native LimitBan_GetSize();

/*********************************************************
 * Returns permission for a specified ban length index.
 *
 * @param index	The specific index to retrieve permission for.
 * @param client	The client to check access for.
 *
 * @return		True if the client has access; False if disabled or no access.
 *********************************************************/
native LimitBan_GetAccess(index, client);

/*********************************************************
 * Provides access to the word form of defined ban lengths.
 *
 * @param index	The specific index to retrieve the display for.
 * @param string	The string to store the index's display in.
 *
 * @return		True if successful; false if disabled or no display set.
 *********************************************************/
native LimitBan_GetDisplay(index, String:buffer[]);

/*********************************************************
 * Returns the number of minutes for a specified ban length index.
 *
 * @return		Number of minutes; -1 if disabled.
 *********************************************************/
native LimitBan_GetLength(index);

/*
 * Do not edit below this line!
 */
 
public SharedPlugin:__pl_limit_ban = 
{
	name = "sm_limit_ban_duration",
	file = "sm_limit_ban_duration.smx",
#if defined REQUIRE_PLUGIN
	required = 1,
#else
	required = 0,
#endif
};

#if !defined REQUIRE_PLUGIN
public __pl_limit_ban_SetNTVOptional()
{
	MarkNativeAsOptional("LimitBan_GetSize");
	MarkNativeAsOptional("LimitBan_GetAccess");
	MarkNativeAsOptional("LimitBan_GetDisplay");
	MarkNativeAsOptional("LimitBan_GetLength");
}
#endif