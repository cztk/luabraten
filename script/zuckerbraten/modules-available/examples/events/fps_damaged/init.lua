local function fps_damaged(damage,dstate,astate,dhealth,ahealth,islocal)
  if damage then
    braten.log_status("DMG: " .. damage)
  end
  if dstate then
    braten.log_status("dstate: " .. dstate)
  end
  if astate then
    braten.log_status("astate: " .. astate)
  end
  if dhealth then
    braten.log_status("dhealth: " .. dhealth)
  end
  if ahealth then
    braten.log_status("ahealth: " .. ahealth)
  end
  if islocal then
    braten.log_status("islocal: " .. tostring(islocal))
  end
end

braten.event_handler("fps_damaged", fps_damaged)
