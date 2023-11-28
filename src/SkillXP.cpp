    #include "SkillXP.h"
 
void GatherXPPlayer::OnUpdateGatheringSkill(Player* player, uint32 skill_id, uint32 current, uint32 gray, uint32 green, uint32 yellow, uint32& gain)
{
    if (!sConfigMgr->GetOption<bool>("GatherXP.Enable", false))
    {
        return; // Gathering XP feature is not enabled
    }
    // Check if player levels up before awarding XP
    if (gain > 0)
    {
        // Calculate XP based on gathering skill event, player's level, etc.
        auto pLevel = player->GetLevel();
        float xpMax = player->GetUInt32Value(PLAYER_NEXT_LEVEL_XP);
        float xpReward = (xpMax * 0.01) / 2;
 
        // Award XP to the player
        player->GiveXP(xpReward, nullptr);
        LOG_INFO("module", "Player Gained {} xp for Gathering", xpReward);
    }
    else
    {
        return;
    }
}
void GatherXPPlayer::OnUpdateCraftingSkill(Player* player, SkillLineAbilityEntry const*, uint32 current_level, uint32& gain)
{
    if (!sConfigMgr->GetOption<bool>("CraftingXP.Enable", false))
    {
        return; // Crafting XP feature is not enabled
    }
    if (gain > 0)
    {
        // Calculate XP based on Crafting skill event, player's level, etc.
        auto pLevel = player->GetLevel();
        float xpMax = player->GetUInt32Value(PLAYER_NEXT_LEVEL_XP);
        float xpReward = (xpMax * 0.01) / 10;
 
        // Award XP to the player
        player->GiveXP(xpReward, nullptr);
        LOG_INFO("module", "Player Gained {} xp Crafting", xpReward);
    }
    else
    {
        return;
    }
}
 
void SC_AddGatherXPScripts()
{
    new GatherXPPlayer();
}