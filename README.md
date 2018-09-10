Description:

    If you've ever needed to limit the amount of time a player can ban for, this plugin is for you! As the name entails, it provides the ability to restrict players from using ban lengths based on an override/flag combination.
    However, it's currently not possible for a plugin to edit entries within the sm_admin menu, so this plugin isn't capable of forcing menu restrictions without editing the corresponding plugin. As such, I've attached pre-edited versions of basebans.smx (v1.4.2) and sourcebans.smx (v1.4.9) that have been modified to obey Limit Ban Duration restrictions, if you wish to use them. If you do not wish to use them, only the sm_ban command will fall under this plugin's restrictions.

Features:

    Provides a command listener for the sm_ban command, supporting Sourcemod's default basebans as well as Sourcebans.
    Provides four natives for usage with other plugins, mainly for adding functionality to basebans/sourcebans.
        LimitBan_GetSize - Returns the current number of defined ban lengths.
        LimitBan_GetDisplay - Provides access to the word form of defined ban lengths.
        LimitBan_GetAccess - Returns permission for a specified ban length index.
        LimitBan_GetLength - Returns the number of minutes for a specified ban length index.
    The configuration file sm_limit_ban_durations.ini allows you to define your own ban lengths (in minutes), and restrict them to custom overrides/flags.
        These times will also be the only available times for the ban entry within sm_admin, provided you're using a modified sourcebans/basebans below.
    Using the feature sm_limit_ban_duration_reduce, ban lengths that are above what an admin has access to will automatically be lowered to the closest ban length that they do possess.
        This feature will also take a permanent punishment and lower it to the highest length the admin has, if the admin doesn't have perm access.
    Using the feature sm_limit_ban_duration_maximum, admins will not be able to ban for any longer than the highest defined entry in the configuration file.
        For example, if this is enabled with the default configuration, a player may not ban for more than 4 weeks, aside from permanently.
        This feature can be combined with sm_limit_ban_duration_reduce to automatically lower a ban length to the maximum allowed.
    If a user tries to issue a ban and doesn't have permission to use any defined lengths, the plugin will simply tell them they do not have access to the command.

ConVars:

    sm_limit_ban_duration_enabled - Enables/disables all features of this plugin.
    sm_limit_ban_duration_reduce - If enabled, the plugin will lower ban lengths if an admin doesn't have access to their specified length to a length they do possess.
    sm_limit_ban_duration_maximum - If enabled, the highest entry defined in the plugins configuration file will be the highest amount any admin can ban for.

Installation:

    /sourcemod/scripting/sm_limit_ban_duration.sp
    /sourcemod/scripting/include/sm_limit_ban_duration.inc
    /sourcemod/plugins/sm_limit_ban_duration.smx
    /sourcemod/translations/sm_limit_ban_duration.phrases.txt
    /sourcemod/configs/sm_limit_ban_duration.ini
    If you wish to have Limit Ban Duration functionality applied to the ban option in sm_admin, you will need to use one of these modified versions. The plugin will automatically move your existing basebans.smx/sourcebans.smx into the /disabled/ folder, so you merely have to upload them to the correct directory. Only upload the one you need! (lbd_basebans to replace the default basebans, or lbd_sourcebans to replace sourcebans)
        /sourcemod/plugins/lbd_basebans.smx
        /sourcemod/plugins/lbd_sbpp_main.smx
        
Pre-Download Config Example:

    "Limit_Ban_Durations"
    {
        "5"
        {
            "override"    ""
            "flags"     ""
        }
        "60"
        {
            "override"    "Basic_Admin"
            "flags"        "b"
        }
        "180"
        {
            "override"    ""
            "flags"        ""
        }
        "720"
        {
            "override"    "High_Admin"
            "flags"        "e"
        }
        "1440"
        {
            "override"    "High_Admin"
            "flags"        "e"
        }
        "0"
        {
            "override"    "Limit_Perm_Ban"
            "flags"        "z"
        }
    }
